var a: array[1..12] of string;
    t, k, i: longint;
    s: string;
begin
readln (s);
read(k);
a[1] := 'January';
a[2] := 'February';
a[3] := 'March';
a[4] := 'April';
a[5] := 'May';
a[6] := 'June';
a[7] := 'July';
a[8] := 'August';
a[9] := 'September';
a[10] := 'October';
a[11] := 'November';
a[12] := 'December';
for i := 1 to 12 do if s = a[i] then t := i;
t := (k + t - 1) mod 12 + 1;
writeln(a[t]);
end.