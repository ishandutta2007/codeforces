function maska(a: longint): longint;
var c: longint;
    code: integer;
    b: string;
begin
  b := '';
  while a > 0 do
  begin
    if (a mod 10 = 4) or (a mod 10 = 7) then
      b := chr(a mod 10 + ord('0')) + b;
    a := a div 10;
  end;
  val(b, c, code);
  maska := c;
end;

var s: string;
    n, i, l, r: longint;
    fail: boolean;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n);
  read(r);

  if n < r then
  begin
    write(r);
    halt;
  end;

  for i := n + 1 to 100000000 do
  begin
    l := maska(i);
    if l = r then
    begin
      write(i);
      halt;
    end;
  end;
end.