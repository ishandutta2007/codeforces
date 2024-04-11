program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  inf = 1000000000000000;

var
  a, b, c, d, ans : int64;
  op1, op2, op3, ch : char;

procedure gen(a, b, c, d, k : int64);
begin
  if k = 1 then begin
    ans := min(ans, a);
    exit;
  end;
  if k = 2 then begin
    if op3 = '+' then
      gen(a + b, 0, 0, 0, 1);
    if op3 = '*' then
      gen(a * b, 0, 0, 0, 1);
    exit;
  end;
  if k = 3 then begin
    if op2 = '+' then begin
      gen(a + b, c, 0, 0, 2);
      gen(a, b + c, 0, 0, 2);
      gen(a + c, b, 0, 0, 2);
    end;
    if op2 = '*' then begin
      gen(a * b, c, 0, 0, 2);
      gen(a, b * c, 0, 0, 2);
      gen(a * c, b, 0, 0, 2);
    end;
    exit;
  end;
  if k = 4 then begin
    if op1 = '+' then begin
      gen(a + b, c, d, 0, 3);
      gen(a + c, b, d, 0, 3);
      gen(a + d, b, c, 0, 3);
      gen(a, b + c, d, 0, 3);
      gen(a, b + d, c, 0, 3);
      gen(a, b, c + d, 0, 3);
    end;
    if op1 = '*' then begin
      gen(a * b, c, d, 0, 3);
      gen(a * c, b, d, 0, 3);
      gen(a * d, b, c, 0, 3);
      gen(a, b * c, d, 0, 3);
      gen(a, b * d, c, 0, 3);
      gen(a, b, c * d, 0, 3);
    end;
    exit;
  end;
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(a, b, c, d);
  read(op1, ch, op2, ch, op3);
  ans := inf;
  gen(a, b, c, d, 4);
  writeln(ans);
end.