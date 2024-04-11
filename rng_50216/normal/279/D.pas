
var z, ans, bc, a, b, n, i, j, k, qn, qm, e, mask, nmask : longint;
    q1, q2, was : array[0 .. 1 shl 23] of longint;
    aa, cn : array[0 .. 111] of longint;
    x, y : array[0 .. 111, 0 .. 1111] of longint;

begin
    read(n);
    if (n = 1) then begin
        writeln(1);
        halt(0);
    end;
    for i := 1 to n do read(aa[i]);
    fillchar(x, sizeof(x), 0);
    fillchar(y, sizeof(y), 0);
    for i := 1 to n do begin
        cn[i] := 0;
        for j := 1 to i - 1 do begin
            for k := j to i - 1 do begin
                if (aa[j] + aa[k] <> aa[i]) then continue;
                x[i][cn[i]] := j;
                y[i][cn[i]] := k;
                inc(cn[i]);
            end;
        end;
    end;
    q1[0] := 2;
    qn := 1;
    fillchar(was, sizeof(was), 0);
    for i := 2 to n - 1 do begin
        qm := 0;
        for j := 0 to qn - 1 do begin
            mask := q1[j];
            for e := 0 to cn[i] - 1 do begin
                a := x[i][e];
                b := y[i][e];
                if (((mask shr a) and 1) = 0) or (((mask shr b) and 1) = 0) then continue;
                for z := 1 to i - 1 do begin
                    if (((mask shr z) and 1) = 1) then begin
                        nmask := mask xor (1 shl z) xor (1 shl i);
                        if was[nmask] = i then continue;
                        was[nmask] := i;
                        q2[qm] := nmask;
                        inc(qm);
                    end;
                end;
                nmask := mask xor (1 shl i);
                if was[nmask] = i then continue;
                was[nmask] := i;
                q2[qm] := nmask;
                inc(qm);
            end;
        end;
        qn := qm;
        for j := 0 to qn - 1 do q1[j] := q2[j];
    end;
    ans := 1 shl 30;
    for z := 0 to qn - 1 do begin
        mask := q1[z];
        bc := 0;
        for i := 1 to n - 1 do if (((mask shr i) and 1) = 1) then inc(bc);
        if ans <= bc then continue;
        for i := 0 to cn[n] - 1 do begin
            a := x[n][i];
            b := y[n][i];
            if (((mask shr a) and 1) = 0) or (((mask shr b) and 1) = 0) then continue;
            ans := bc;
            break;
        end;
    end;
    if (ans = 1 shl 30) then writeln(-1) else writeln(ans);
end.