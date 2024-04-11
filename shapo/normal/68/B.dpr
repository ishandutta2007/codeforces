program b;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const eps = 1e-10;

var n, k, i, mx, mn : integer;
    l, r, m, sum1, sum2 : extended;
    a : array[1..10000] of integer;

begin
    readln(n, k);
    k := 100 - k;
    mx := 1001;
    mn := -1;
    for i := 1 to n do begin
        read(a[i]);
        mn := min(mn, a[i]);
        mx := max(mx, a[i]);
    end;
    l := mn;
    r := mx;
    while (r - l > eps) do begin
        m := (l + r) / 2;
        sum1 := 0;
        sum2 := 0;
        for i := 1 to n do
            if (a[i] < m) then sum2 := sum2 + m - a[i]
            else sum1 := sum1 + a[i] - m;
        if (sum1 * k >= sum2 * 100) then l := m else r := m;
    end;
    writeln((l + r) / 2 : 0 : 10);
end.