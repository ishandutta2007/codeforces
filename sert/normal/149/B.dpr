program a106b;

{$APPTYPE CONSOLE}

type tdmas = array[1..100000] of longint;

function num(var ch: char): integer;
begin
  if (ch <= '9') and (ch >= '0') then num := ord(ch) - ord('0') else
  if (ch <= 'Z') and (ch >= 'A') then num := ord(ch) - ord('A') + 10 else num := -1;
end;

function to10(var s: string; sys: integer): int64;
var rez: int64;
    i, j, p, k: longint;
    q: int64;
begin
  q := 1;
  rez := 0;
  for i := length(s) downto 1 do
  begin
    rez := rez + num(s[i]) * q;
    q := q * sys;
  end;
  to10 := rez;
end;

var s, k: string;
    kf, ks, n, i, j, t: longint;
    max: longint;
    f, a, b: Tdmas;
    sys: array[1..50] of char;

begin
  randomize;
  //reset(input,'i.i');
  read(s);
  delete(s, 15, length(s));
  while s[length(s)] = ' ' do delete(s, length(s), 1);
  //if (length(s) = 3) then begin write(-1); halt; end;
  max := 0;
  for i := 1 to length(s) do
    if num(s[i]) > max then max := num(s[i]);
  for i := 1 to length(s) do if s[i] = ':' then t := i;
  k := '';
  for i := t + 1 to length(s) do k := k + s[i];
  delete(s, t, length(s));
  while (s[1] = '0') and (s <> '0') do delete(s, 1, 1);
  while (k[1] = '0') and (k <> '0') do delete(k, 1, 1);
  if (length(s) + length(k) = 2) and (num(s[1]) <= 23) then begin write(-1); halt; end;
  //s:k
  for i := max + 1 to 60 do
  begin
    if to10(s, i) > 23 then begin if i = max + 1 then write('0'); halt; end;
    if to10(k, i) > 59 then begin if i = max + 1 then write('0'); halt; end;
    write(i, ' ');
  end;


end.