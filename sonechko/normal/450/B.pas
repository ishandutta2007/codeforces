var a:array[1..10] of int64;
    i,j,k,m,l,o,p,n:longint;
  begin
    read(a[1],a[2]);
    a[3]:=a[2]-a[1];
    a[4]:=-1*a[1];
    a[5]:=-1*a[2];
    a[6]:=-1*a[3];
    read(n);
    n:=n mod 6;
    if n=0 then n:=6;
    if a[n]>=0 then write(a[n] mod 1000000007)
               else write(((a[n] mod 1000000007)+1000000007) mod 1000000007);
 End.