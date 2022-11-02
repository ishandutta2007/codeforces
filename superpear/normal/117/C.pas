var indx,e,mlik,num,stack,where,outp,ok:array[0..10000] of longint;
    a:array[0..5000,0..5000] of integer;
    i,n,min,mink,o,j,k,tot,top,visit,ee:longint;
    ch:char;

procedure search(s:longint);
  var i:longint;
  begin
    inc(visit);
    indx[s]:=visit;
    mlik[s]:=visit;
    inc(top);
    stack[top]:=s;
    for i:=1 to n do
      if a[s,i]=1 then
        begin
          if indx[i]=0 then search(i);
          if mlik[i]<mlik[s] then
            mlik[s]:=mlik[i];
        end;
    if indx[s]=mlik[s] then
      begin
        inc(tot);
        repeat
          where[stack[top]]:=tot;
          mlik[stack[top]]:=n+1;
          dec(top);
        until stack[top+1]=s;
      end;
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to n do
        begin
          read(ch);
          a[i,j]:=ord(ch)-48;
        end;
      readln;
    end;
  tot:=0;
  visit:=0;
  top:=0;
  fillchar(stack,sizeof(stack),0);
  fillchar(indx,sizeof(indx),0);
  fillchar(mlik,sizeof(mlik),0);
  fillchar(where,sizeof(where),0);
  for i:=1 to n do
    if indx[i]=0 then search(i);
  fillchar(num,sizeof(num),0);
  for i:=1 to n do
    inc(num[where[i]]);
  min:=maxlongint;
  mink:=0;
  for i:=1 to tot do
    if (num[i]>=3) and (num[i]<=min) then
      begin
        min:=num[i];
        mink:=i;
      end;
  if mink=0 then
    begin
      writeln(-1);
      halt;
    end;
  o:=0;
  for i:=1 to n do
    if where[i]=mink then
      begin
        inc(o);
        e[o]:=i;
      end;
  for i:=1 to o do
    for j:=1 to o do
      if a[e[i],e[j]]=1 then
        begin
          for k:=1 to o do
            if (a[e[j],e[k]]=1) and (a[e[k],e[i]]=1) then
              begin
                writeln(e[i],' ',e[j],' ',e[k]);
                halt;
              end;
        end;
end.