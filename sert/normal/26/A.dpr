

    var a: array[1..2000] of longint;
    s: array[1..200, 1..200] of longint;
    kol, q, n, t, r, m, i, j: longint;

    begin
    //reset(input,'input.txt');
    //rewrite(output,'output.txt');
    a[1] := 2;
    a[2] := 3;
    a[3] := 5;
    a[4] := 7;
    a[5] := 11;
    a[6] := 13;
    a[7] := 17;
    a[8] := 19;
    a[9] := 23;

    a[10] := 29;
    a[11] := 31;
    a[12] := 37;
    a[13] := 41;
    a[14] := 43;
    a[15] := 47;

    a[16] := 53;
    m := 16;
    for i := 57 to 3000 do
    begin
      q := 0;
      for j := 1 to 16 do if i mod a[j] = 0 then q := 1;
      if q = 0 then begin inc(m); a[m] := i; end;
    end;
    for i := m + 1 to 1000 do a[i] := 4000;
    read(n);
    kol := 0;
    for i := 1 to n do
    begin
      t := 0;
      for j := 1 to 1000 do if i mod a[j] = 0 then inc(t);
      if t = 2 then inc(kol);
    end;
    write(kol);
end.