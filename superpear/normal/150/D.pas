const maxn=160;

var n,i,j,k:longint;
    best,full:array[0..maxn,0..maxn] of longint;
    t:array[0..maxn,0..maxn,0..maxn] of longint;
    c:array[0..maxn] of longint;
    s:array[0..maxn] of char;

procedure search(flag,l,r,len:longint);
  var i:longint;
  begin
    if flag=1 then
      begin
        if l>r then exit;
        if best[l,r]<>-1 then exit;
        best[l,r]:=0;
        search(2,l,r,0);
        if (full[l,r]>=0) and (full[l,r]>best[l,r]) then best[l,r]:=full[l,r];
        for i:=l to r-1 do
          begin
            search(1,l,i,0);
            search(1,i+1,r,0);
            if (best[l,i]>=0) and (best[i+1,r]>=0) and (best[l,i]+best[i+1,r]>best[l,r]) then
              best[l,r]:=best[l,i]+best[i+1,r];
          end;
        exit;
      end;
    if flag=2 then
      begin
        if l>r then exit;
        if full[l,r]<>-1 then exit;
        full[l,r]:=-2;
        for i:=1 to n do
          if c[i]>=0 then
            begin
              search(3,l,r,i);
              if t[l,r,i]>=0 then
                if t[l,r,i]+c[i]>full[l,r] then
                  full[l,r]:=t[l,r,i]+c[i];
            end;
        exit;
      end;
    if flag=3 then
      begin
        if t[l,r,len]<>-1 then exit;
        t[l,r,len]:=-2;
        if len>r-l+1 then exit;
        if len=0 then
          begin
            if l>r then
              begin
                t[l,r,len]:=0;
                exit;
              end;
            flag:=1;
            for i:=l to r do
              if s[i]<>s[l+r-i] then
                begin
                  flag:=0;
                  break;
                end;
            if (c[r-l+1]>=0) and (flag=1) then
              t[l,r,len]:=c[r-l+1];
            search(2,l,r,0);
            if (full[l,r]>=0) and (full[l,r]>t[l,r,len]) then
              t[l,r,len]:=full[l,r];
          end;
        if len=1 then
          begin
            if l=r then
              begin
                t[l,r,len]:=0;
                exit;
              end;
            search(2,l,r-1,0);
            if (full[l,r-1]>=0) and (full[l,r-1]>t[l,r,len]) then
              t[l,r,len]:=full[l,r-1];
            search(2,l+1,r,0);
            if (full[l+1,r]>=0) and (full[l+1,r]>t[l,r,len]) then
              t[l,r,len]:=full[l+1,r];
            for i:=l+1 to r-1 do
              begin
                search(2,l,i-1,0);
                search(2,i+1,r,0);
                if (full[l,i-1]>=0) and (full[i+1,r]>=0) then
                  if full[l,i-1]+full[i+1,r]>t[l,r,len] then
                    t[l,r,len]:=full[l,i-1]+full[i+1,r];
              end;
          end;
        for i:=l to r-1 do
          begin
            search(2,l,i,0);
            search(3,i+1,r,len);
            if (full[l,i]>=0) and (t[i+1,r,len]>=0)
               and (full[l,i]+t[i+1,r,len]>t[l,r,len]) then
                 t[l,r,len]:=full[l,i]+t[i+1,r,len];
            search(2,i+1,r,0);
            search(3,1,i,len);
            if (full[i+1,r]>=0) and (t[l,i,len]>=0)
               and (full[i+1,r]+t[l,i,len]>t[l,r,len]) then
                 t[l,r,len]:=full[i+1,r]+t[l,i,len];
          end;
        if (len>=2) and (l<r) and (s[l]=s[r]) then
          begin
            search(3,l+1,r-1,len-2);
            if t[l+1,r-1,len-2]>=0 then
              if t[l+1,r-1,len-2]>t[l,r,len] then
                t[l,r,len]:=t[l+1,r-1,len-2];
          end;
      end;
  end;

begin
  readln(n);
  for i:=1 to n do
    read(c[i]);
  readln;
  for i:=1 to n do
    read(s[i]);
  readln;
  //1: best[l,r]
  //2: full[l,r]
  //3: t[l,r,len]
  fillchar(best,sizeof(best),255);
  fillchar(full,sizeof(full),255);
  fillchar(t,sizeof(t),255);
  search(1,1,n,0);
  if best[1,n]<=0 then writeln(0) else writeln(best[1,n]);
end.