var a,b,n:longint;

function gcd(a,b:longint):longint;
  begin
    if b=0 then exit(a) else exit(gcd(b,a mod b));
  end;

begin
  readln(a,b,n);
  while n>0 do
    begin
      n:=n-gcd(n,a);
      if n=0 then
        begin
          writeln(0);
          break;
        end;
      n:=n-gcd(n,b);
      if n=0 then
        begin
          writeln(1);
          break;
        end;
    end;
end.