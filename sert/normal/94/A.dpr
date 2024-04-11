var s: array [1..10] of string;
    ss, str: string;
    i, j, n, k, ii: longint;
begin

  readln(ss);
  for i := 1 to 10 do
    readln(s[i]);

  i := 1;

  for j := 1 to 8 do
  begin
    str := '';
    for ii := 1 to 10 do
    begin
      str := str + ss[i];
      inc(i);
    end;
    for ii := 1 to 10 do
      if s[ii] = str then
        write(ii - 1);
  end;
end.