program B;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var s, s1 : string;
    i : integer;
    a : array[0..5000] of integer;

procedure obr(p : string);
var s : string;
    cur : integer;
begin
    i := i + 2;
    inc(a[0]);
    cur := a[0];
    a[a[0]] := 0;
    s := '';
    while (p[i] <> '>') do begin
        s := s + p[i];
        inc(i);
    end;
    while (s <> '/table') do begin
        if (s = 'td') then inc(a[cur]);
        if (s = 'table') then obr(p);
        while (p[i] <> '<') do inc(i);
        s := '';
        inc(i);
        while (p[i] <> '>') do begin
            s := s + p[i];
            inc(i);
        end;
    end;
end;

procedure qsort(l, r : integer);
var i, j, x, buf : integer;
begin
    i := l;
    j := r;
    x := a[random(r - l + 1) + l];
    repeat
        while (a[i] < x) do inc(i);
        while (a[j] > x) do dec(j);
        if i <= j then begin
            buf := a[i];
            a[i] := a[j];
            a[j] := buf;
            inc(i);
            dec(j);
        end;
    until i > j;
    if i < r then qsort(i, r);
    if l < j then qsort(l, j);
end;

begin
//    assign(input, 'input.txt');
    readln(s1);
    s := '';
//    while not(eof) do begin
    while (s1 <> '') do begin
//        readln(s1);
        s := s + s1;
        readln(s1);
    end;
    a[0] := 0;
    i := 1;
    while (s[i] <> '<') do inc(i);
    while (s[i] <> '>') do inc(i);
    obr(s);
    random;
    qsort(1, a[0]);
    for i := 1 to a[0] do begin
        write(a[i], ' ');
    end;
    writeln;
end.