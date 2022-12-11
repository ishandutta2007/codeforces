

    var a, st: array[1..1000001] of shortint;
    s: string;
    kol, q, n, t, r, m, i, j, len: longint;

    begin
    //reset(input,'input.txt');
   // rewrite(output,'output.txt');
    readln(s);
    for i := 1 to length(s) do
    if s[i] = '(' then a[i] := 1 else a[i] := -1;
    len := 1;
    st[1] := a[1];
    for i := 2 to length(s) do
    begin
      if (st[len] = 1)and(a[i] = -1) then begin dec(len); inc(kol); end else
      if (a[i] = 1) then begin
      inc(len);
      st[len] := a[i];        end;
    end;
    write(kol * 2);
end.