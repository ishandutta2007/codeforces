type stack = record
con: array[1..1000] of char;
len: integer;
end;

procedure wc (q: integer; ch: char; s: string);
var i: integer;
begin
  for i := 1 to q do write(' ');
  write('<');
  if s = 'close' then write('/');
  writeln(ch,'>');
end;

var a, b, c, j, i, n, k, m, len: longint;
    s, st: string;
    stac: stack;
begin
//reset(input,'i.i');
//rewrite(output,'o.o');
read(s);
for i := 1 to length(s) do
if (s[i] >= 'a') and (s[i] <= 'z') then
if s[i-1] = '/' then begin dec(stac.len); wc(2*stac.len, s[i], 'close'); end
else begin inc(stac.len); wc(2*stac.len-2, s[i], 'open'); end;
end.