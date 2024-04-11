var n,m,i,j,k,l,r:longint;
    a:array[1..200000]of longint;
    b:array[1..200000]of boolean;
  begin
    read(n,m,l);
    for i:=1 to n do
     read(a[i]);
    for i:=1 to n do
     if a[i]<=m then b[i]:=true else b[i]:=false;
    i:=1;
    while i<=n do
     begin
      k:=n;
      for j:=i to n do
       if b[j]=false then begin k:=j-1; break; end;
      if((k-i+1)-l+1)>0 then  r:=r+((k-i+1)-l+1);
      i:=k+2;
     end;
    writeln(r);
  end.