program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  inf = 2000000000;
  eps = 0.000000001;

var
  n, k, i : integer;
  a, b : array[0..100001] of integer;
  c : array[0..100001] of extended;
  l, r : array[0..100001] of boolean;

function eq(a, b : extended) : boolean;
begin
  result := abs(a - b) < eps;
end;

function f(a, b : extended) : extended;
begin
  if eq(a, 0) then begin
    if eq(b, 0) then
      result := 0
    else
      result := inf;
  end
  else
    result := b / a;
end;

procedure init;
begin
  k := 0;
end;

procedure add(l, r : integer);
var i : integer;
begin
  for i := l to r do begin
    inc(k);
    b[k] := a[i];
  end;
end;

function check : boolean;
var i : integer;
begin
  result := true;
  for i := 2 to k do
    c[i] := f(b[i - 1], b[i]);
  for i := 3 to k do
    if not eq(c[i - 1], c[i]) then begin
      result := false;
      exit;
    end;
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(a[i]);
  if n = 1 then begin
    write(0);
    halt(0);
  end;
  if n = 2 then begin
    if eq(f(a[1], a[2]), inf) then
      write(1)
    else
      write(0);
    halt(0);
  end;
  init;
  add(1, n);
  if check then begin
    write(0);
    halt(0);
  end;
  init;
  add(2, n);
  if check then begin
    write(1);
    halt(0);
  end;
  init;
  add(1, n - 1);
  if check then begin
    write(1);
    halt(0);
  end;
  init;
  add(1, 1);
  add(3, n);
  if check then begin
    write(1);
    halt(0);
  end;
  init;
  add(1, n - 2);
  add(n, n);
  if check then begin
    write(1);
    halt(0);
  end;
  for i := 2 to n do
    c[i] := f(a[i - 1], a[i]);
  l[2] := true;
  for i := 3 to n do begin
    l[i] := l[i - 1];
    if not eq(c[i - 1], c[i]) then begin
      l[i] := false;
      break;
    end;
  end;
  r[n] := true;
  for i := n - 1 downto 2 do begin
    r[i] := r[i + 1];
    if not eq(c[i], c[i + 1]) then begin
      r[i] := false;
      break;
    end;
  end;
  for i := 3 to n - 2 do
    if (l[i - 1]) and (r[i + 2]) and (eq(c[2], c[n])) and (eq(c[2], f(a[i - 1], a[i + 1]))) then begin
      write(1);
      halt(0);
    end;
  write(2);
end.