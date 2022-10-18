var n,m,i,j,k,l,r:longint;
    a:array[1..1000]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       a[i]:=l mod 2;
     end;
    l:=0;r:=0;
    for i:=1 to n do
     if a[i]=0 then inc(l) else inc(r);
    for i:=1 to n do
     if (a[i]=0) and (l=1) then begin writeln(i); halt; end else
     if (a[i]=1) and (r=1) then begin writeln(i); halt; end;

  end.