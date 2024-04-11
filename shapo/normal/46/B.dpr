program B;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n : array[-5..10] of integer;
    k, i, cur, a, b1 : integer;
    s : string;
    res : array[1..1000] of integer;

function op(s : string) : integer;
begin
    if s = 'S' then op := 1;
    if s = 'M' then op := 2;
    if s = 'L' then op := 3;
    if s = 'XL' then op := 4;
    if s = 'XXL' then op := 5;
end;

function po(n : integer) : string;
begin
    if n = 1 then po := 'S';
    if n = 2 then po := 'M';
    if n = 3 then po := 'L';
    if n = 4 then po := 'XL';
    if n = 5 then po := 'XXL';
end;

begin
    fillchar(n, sizeof(n), 0);
    for i := 1 to 5 do
        read(n[i]);
    readln;
    readln(k);
    for i := 1 to k do begin
        readln(s);
        cur := op(s);
        a := cur;
        b1 := cur;
        while (n[a] = 0) and (n[b1] = 0) do begin
            inc(a);
            dec(b1);
        end;
        if (n[a] <> 0) then res[i] := a else res[i] := b1;
        if (n[a] <> 0) then dec(n[a]) else dec(n[b1]);
    end;
    for i := 1 to k do begin
        writeln(po(res[i]));
    end;
end.