program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const maxn = 200;

var n, m, i, j, cur, tcp, res : longint;
    l, r : array[1..maxn] of longint;

procedure init;
var i : longint;
begin
    for i := 1 to maxn do begin
        l[i] := maxn + 1;
        r[i] := 0;
    end;
end;

procedure readc(x, y : longint);
var c : char;
begin
    read(c);
    //writeln(c);
    if c = 'W' then begin
        l[x] := min(l[x], y);
        r[x] := max(r[x], y);
    end;
end;

procedure obr(x : longint);
begin
    //writeln('x :', x);
    if (x mod 2 = 1) then begin
        res := res + max(max(tcp, r[x]), r[x + 1]) - tcp;
        tcp := max(max(tcp, r[x]), r[x + 1]);
    end
    else begin
        res := res + tcp - min(min(tcp, l[x]), l[x + 1]);
        tcp := min(min(tcp, l[x]), l[x + 1]);
    end;
end;

begin
    //assign(input, 'input.txt');
    init;
    readln(n, m);
    res := 0;
    for i := 1 to n do begin
        for j := 1 to m do
            readc(i, j);
        readln;
    end;
    cur := 0;
    i := n;
    while (i > 0) and (l[i] > r[i]) do dec(i);
    //writeln(i);
    cur := max(cur, i);
    tcp := 1;
    for i := 1 to cur do begin
        obr(i);
        //writeln(tcp);
    end;
    res := max(res + cur - 1, 0);
    //writeln(cur);
    writeln(res);
    halt(0);
end.