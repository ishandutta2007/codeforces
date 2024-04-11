program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type migr = record
    s : string;
    n, ee : longint;
    used : boolean;
end;

var n, m, i, num, n1, k1 : longint;
    k : extended;
    sm, res : array[1..100] of migr;
    neww, ol : array[1..100] of migr;

procedure inputq(u : longint);
var c : char;
begin
    read(c);
    sm[i].s := '';
    while c <> ' ' do begin
        sm[i].s := sm[i].s + c;
        read(c);
    end;
    readln(sm[i].n);
    sm[i].ee := (sm[i].n * k1) div 100;
    sm[i].used := sm[i].ee >= 100;
end;

procedure merge;
var i : longint;
begin
    n1 := 0;
    for i := 1 to n do
        if sm[i].used then begin
            inc(n1);
            ol[n1] := sm[i];
        end;
    for i := 1 to m do begin
        inc(n1);
        ol[n1] := neww[i];
    end;
end;

function less(a, b : migr) : boolean;
begin
    less := (a.s < b.s) or ((a.s = b.s) and (a.ee > b.ee));
end;

procedure obr;
var i, j : longint;
    buf : migr;
begin
    for i := 2 to n1 do
        for j := n1 downto i do
            if less(ol[j], ol[j - 1]) then begin
                buf := ol[j];
                ol[j] := ol[j - 1];
                ol[j - 1] := buf;
            end;
    buf := ol[1];
    inc(num);
    res[num] := buf;
    for i := 2 to n1 do
        if ol[i].s <> buf.s then begin
            buf := ol[i];
            inc(num);
            res[num] := buf;
        end;
end;

begin
    //assign(input, 'input.txt');
    //assign(output, 'output.txt');
    readln(n, m, k);
    k1 := trunc(k * 100);
    num := 0;
    for i := 1 to n do
        inputq(i);
    for i := 1 to m do begin
        readln(neww[i].s);
        neww[i].ee := 0;
        neww[i].used := true;
    end;
    merge;
    obr;
    writeln(num);
    for i := 1 to num do
        writeln(res[i].s, ' ', res[i].ee);
    halt(0);
end.