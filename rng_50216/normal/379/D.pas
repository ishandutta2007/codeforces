
const ALPH = 'ACD';
var z, i, k, x, n, m, c1, c2, d1, d2, len1, len2, e1, e2 : longint;
    f1, f2 : array[0 .. 123] of longint;
    cn : array[0 .. 123] of int64;
    ans1, ans2 : array[0 .. 123] of char;

begin
  read(k, x, n, m);
  for c1 := 0 to 2 do
    for c2 := 0 to 2 do if (n > 1) or (c1 = c2) then
      for d1 := 0 to 2 do
        for d2 := 0 to 2 do if (m > 1) or (d1 = d2) then begin
          len1 := n;
          if c1 = 1 then dec(len1);
          if c2 = 0 then dec(len1);
          len1 := len1 div 2;
          len2 := m;
          if d1 = 1 then dec(len2);
          if d2 = 0 then dec(len2);
          len2 := len2 div 2;
          for e1 := 0 to len1 do begin            
            for e2 := 0 to len2 do begin
              if (c1 = 0) and (c2 = 1) and (e1 = 0) then continue;
              if (d1 = 0) and (d2 = 1) and (e2 = 0) then continue;
              f1[1] := c1;
              f2[1] := c2;
              f1[2] := d1;
              f2[2] := d2;
              cn[1] := e1;
              cn[2] := e2;
              for i := 3 to k do begin
                cn[i] := cn[i - 1] + cn[i - 2];
                if (f2[i - 2] = 0) and (f1[i - 1] = 1) then cn[i] += 1;
                f1[i] := f1[i - 2];
                f2[i] := f2[i - 1];
              end;
              if cn[k] = x then begin
                ans1[1] := ALPH[c1 + 1];
                if c1 <> 0 then
                  i := 2 else i := 1;
                for z := 1 to e1 do begin
                  ans1[i] := 'A';
                  ans1[i + 1] := 'C';
                  i += 2;
                end;
                while (i <= n) do begin
                  ans1[i] := 'D';
                  inc(i);
                end;
                ans1[n] := ALPH[c2 + 1];
                ans2[1] := ALPH[d1 + 1];
                if d1 <> 0 then
                  i := 2 else i := 1;
                for z := 1 to e2 do begin
                  ans2[i] := 'A';
                  ans2[i + 1] := 'C';
                  i += 2;
                end;
                while (i <= m) do begin
                  ans2[i] := 'D';
                  inc(i);
                end;
                ans2[m] := ALPH[d2 + 1];
                for i := 1 to n do write(ans1[i]);
                writeln;
                for i := 1 to m do write(ans2[i]);
                writeln;
                halt(0);
              end;
            end;
          end;
        end;
  writeln('Happy new year!');
end.