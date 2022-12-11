program cdfss88;

{$APPTYPE CONSOLE}

var n, m, i, j, k, s, p, a, b,t, md, ch, min: longint;
    st: string;

begin
//reset(input,'i.i');
//rewrite(output,'o.o');
read(n, m);
for i := 1 to n do
begin
   read(a, b, t);
   if a = b then writeln(t);
   if a < b then
   begin
     p := ((t - a + 2 * m - 2) div (2* m - 2)) * (2 * m - 2) + (a - 1) mod (2 * m - 2);
     writeln(p + b - a);
   end;
   if a > b then
   begin
     
     p :=((t - 2 * m + a + 2*m-2) div (2* m - 2)) * (2 * m - 2) + (2*m-1-a) mod (2 * m - 2);
     writeln(p + a - b);
   end;

end;
end.