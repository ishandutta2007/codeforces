
var n, m, k, i, j: longint;
    s, t, y: string;
begin
  k := 0;
  m := 0;
 readln(n);
 readln(s);
 inc(m);
 for i := 2 to n do
 begin
 readln(t);
 if t = s then inc(m) else begin y := t; inc(k); end;
 end;
 if m > k then write(s) else write(y);

end.