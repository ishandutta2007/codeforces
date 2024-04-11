const bigp=1000000007;

var n,i,s:longint;

function pow(a,b:longint):longint;
  var d:longint;
  begin
    if b=0 then exit(1);
    d:=pow(a,b div 2);
    d:=int64(d)*d mod bigp;
    if b mod 2=1 then d:=int64(d)*a mod bigp;
    exit(d);
  end;

begin
  readln(n);
  s:=1;
  for i:=n*2-1 downto n+1 do
    s:=s*int64(i) mod bigp;
  for i:=1 to n-1 do
    s:=s*int64(pow(i,bigp-2)) mod bigp;
  writeln((int64(s)*2-n+bigp) mod bigp);
end.