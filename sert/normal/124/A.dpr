program q;

{$APPTYPE CONSOLE}
function max (var a, b: longint): longint;
begin
  if a > b then max := a else max := b;
end;

var a, b, n, k: longint;
begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n, a, b);
  inc(b);
  k := n - b;
  write(n - max(a, k));
end.