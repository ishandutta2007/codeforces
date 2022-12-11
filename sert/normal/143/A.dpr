program C101a;

{$APPTYPE CONSOLE}

var //a: array[1..100000] of longint;
    s: string;
    a, b, c, d, r1, r2, c1, c2, d1, d2, ii, jj, n, m, i, j, t, p: longint;
    fail: boolean;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');

  fail := true;

  read(r1, r2, c1, c2, d1, d2);
  for i := 1 to 9 do
    for j := 1 to 9 do
      for ii := 1 to 9 do
        for jj := 1 to 9 do
          if (i - j) * (i - ii) * (i - jj) * (j - ii) * (j - jj) * (jj - ii) <> 0 then
            if (i + j = r1)and(ii + jj = r2)and(i + ii = c1)and(j + jj = c2)and(i + jj = d1)and(j + ii = d2) then
            begin
              writeln(i, ' ', j);
              writeln(ii, ' ', jj);
              halt;
            end;
  write('-1');
end.