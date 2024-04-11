const bigp=1000000009;

type autoac=^pear;
     pear=record
            flag,depth,num,ti:longint;
            back,father:autoac;
            child:array[1..4] of autoac;
          end;

var root,p,q:autoac;
    m,n,i,j,k,tt,ls,rc,fc,sc,ans:longint;
    f:array[0..1010,0..300,0..15] of longint;
    u:array[0..10000] of autoac;
    s:string;
    ch:char;

procedure doit(p:autoac;s:longint);
  var i,j,c1,c2:longint;
      q:autoac;
  begin
    if (s=0) or (p<>root) then
      begin
        for i:=1 to 4 do
          begin
            c1:=p^.ti;
            q:=p;
            while (q<>root) and (q^.child[i]=nil) do q:=q^.back;
            if q^.child[i]<>nil then
              q:=q^.child[i];
            c2:=q^.ti;
            for j:=0 to 10 do
              if f[s,c1,j]>0 then
                begin
                  if (q^.flag=1) and (q^.depth>j) then
                    f[s+1,c2,0]:=(f[s+1,c2,0]+f[s,c1,j]) mod bigp
                  else
                    f[s+1,c2,j+1]:=(f[s+1,c2,j+1]+f[s,c1,j]) mod bigp;
                end;
          end;
      end;
    for i:=1 to 4 do
      if p^.child[i]<>nil then
        doit(p^.child[i],s);
  end;

procedure solve(p:autoac);
  var i:longint;
  begin
    if p^.flag=1 then
      ans:=(ans+f[n,p^.ti,0]) mod bigp;
    for i:=1 to 4 do
      if p^.child[i]<>nil then
        solve(p^.child[i]);
  end;

begin
  new(root);
  root^.father:=root;
  root^.back:=root;
  root^.num:=0;
  root^.ti:=1;
  root^.depth:=0;
  root^.flag:=0;
  for i:=1 to 4 do
    root^.child[i]:=nil;
  readln(n,m);
  tt:=1;
  for i:=1 to m do
    begin
      readln(s);
      p:=root;
      ls:=length(s);
      for j:=1 to ls do
        begin
          ch:=s[j];
          if ch='A' then sc:=1;
          if ch='C' then sc:=2;
          if ch='G' then sc:=3;
          if ch='T' then sc:=4;
          if p^.child[sc]=nil then
            begin
              new(q);
              q^.father:=p;
              q^.back:=nil;
              for k:=1 to 4 do
                q^.child[k]:=nil;
              inc(tt);
              q^.ti:=tt;
              q^.num:=sc;
              q^.flag:=0;
              p^.child[sc]:=q;
              p:=q;
            end
          else
            p:=p^.child[sc];
        end;
      p^.flag:=1;
      p^.depth:=ls;
    end;
  rc:=1;
  fc:=1;
  u[rc]:=root;
  while rc<=fc do
    begin
      if u[rc]<>root then
        begin
          p:=u[rc]^.father^.back;
          sc:=u[rc]^.num;
          while (p<>root) and (p^.child[sc]=nil) do p:=p^.back;
          if (p^.child[sc]<>nil) and (p^.child[sc]<>u[rc]) then p:=p^.child[sc];
          u[rc]^.back:=p;
          p:=u[rc];
          if p^.flag=0 then
            begin
              q:=p^.back;
              while (q<>root) and (q^.flag=0) do q:=q^.back;
              if q^.flag=1 then
                begin
                  p^.flag:=1;
                  p^.depth:=q^.depth;
                end;
            end;
        end;
      for i:=1 to 4 do
        if u[rc]^.child[i]<>nil then
          begin
            inc(fc);
            u[fc]:=u[rc]^.child[i];
          end;
      inc(rc);
    end;
  fillchar(f,sizeof(f),0);
  f[0,1,0]:=1;
  for i:=0 to n-1 do
    doit(root,i);
  ans:=0;
  solve(root);
  writeln(ans);
end.