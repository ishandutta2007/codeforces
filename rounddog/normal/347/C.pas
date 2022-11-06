program cf201_3;

var
    i,j,k,l,m,n,gcd,x,y:longint;
    a:array[0..102] of longint;

begin
  readln(n);
  read(a[1]);
  l:=a[1];
  m:=a[1];
  for i:= 2 to n do
    begin
      read(a[i]);
      x:=l;
      y:=a[i];
      repeat
        gcd:=x mod y;
        x:=y;
        y:=gcd;
      until gcd=0;
      l:=x;
      if a[i]>m then m:=a[i];
    end;
  readln;
  if (m div l-n) mod 2=0 then writeln('Bob') else writeln('Alice');
end.