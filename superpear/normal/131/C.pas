var m,n,t,e,i,j,o:longint;
    ans:int64;
    a,b:array[0..1000] of longint;

function gcd(a,b:longint):longint;
  begin
    if b=0 then exit(a) else exit(gcd(b,a mod b));
  end;

function c(m,n:longint):int64;
  var ans:int64;
      i,j,o:longint;
  begin
    o:=0;
    for i:=m downto m-n+1 do
      begin
        inc(o);
        a[o]:=i;
      end;
    for i:=1 to n do b[i]:=i;
    for i:=1 to o do
      for j:=1 to n do
        begin
          e:=gcd(a[i],b[j]);
          a[i]:=a[i] div e;
          b[j]:=b[j] div e;
        end;
    ans:=1;
    for i:=1 to o do ans:=ans*int64(a[i]);
    exit(ans);
  end;

begin
  readln(n,m,t);
  ans:=0;
  for i:=4 to t-1 do
    ans:=ans+int64(c(n,i))*c(m,t-i);
  writeln(ans);
end.