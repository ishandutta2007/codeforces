program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type ttt= array[1..20]of longint;

var a : array[1..20]of ttt;
    n, i, j : longint;
    k, p : longint;

begin
    //reset(input, 'input.txt');
    //rewrite(output, 'output.txt');
    readln(n);
    inc(n);
    for i := 1 to 2*n - 1 do
        for j := 1 to 2*n- 1 do
            a[i][j] := -1;
    for i := 1 to 2 * n - 1 do begin
        if (i > n) then k := 2 * n - i - 1 else k := i - 1;
        p := k;
        j := n;
        while (p >= 0) do begin
            a[i][j] := p;
            dec(p);
            dec(j);
        end;
        p := k;
        j := n;
        while (p >= 0) do begin
            a[i][j] := p;
            dec(p);
            inc(j);
        end;
    end;
    for i:=1 to 2*n - 1 do begin
        if (i > n) then k := 2 * n - i - 1 else k := i - 1;
        p := n + k;
        for j := 1to p do begin
            if a[i][j] = -1 then write(' ') else write(a[i][j]);
            if j <> p then write(' ') else writeln;
        end;
    end;
    halt(0);
end.