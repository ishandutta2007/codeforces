program oject1;

{$APPTYPE CONSOLE}

var i: longint;
    a: array[0..101, 0..101] of char;
    ii, n, m, j, k, p, s: longint;
begin
        //reset(input,'i.i');
  //      rewrite(output,'o.o');
readln(n, m);
for i := 1 to n do begin for j := 1 to m do read(a[i, j]); readln; end;
for i := 1 to n do for j := 1 to m do
begin
  s := 0;
  for ii := 1 to m do if (ii <> j) and (a[i,j]=a[i,ii]) then s := 1;
  for ii := 1 to n do if (ii <> i) and (a[i,j]=a[ii,j]) then s := 1;
  if s = 0 then write(a[i,j]);
end;
end.