program a99;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var i, j, n: longint;
    a: array[1..7] of longint;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n);
  for i := 1 to 7 do read(a[i]);
  i := 0;
  while 1 < 2 do
  begin
    i := i mod 7 + 1;
    n := n - a[(i - 1) mod 7 + 1];
    if n <= 0 then begin write((i - 1) mod 7 + 1); halt; end;
  end;
end.