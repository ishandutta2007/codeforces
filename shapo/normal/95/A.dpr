program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var w, w1, res, s, s1 : string;
    conv, used : array[1..100] of boolean;
    cov : array[1..100] of longint;
    sm : array[1..100] of string;
    sm1 : array[1..100] of string;
    len1 : array[1..100] of longint;
    len, i, l, j, n : longint;
    letter : char;

function transf(c : char) : char;
begin
    transf := chr(ord(c) - 32);
end;

function tr(s : string) : string;
var i : longint;
    res : string;
begin
    res := '';
    for i := 1 to length(s) do begin
        if ord(s[i]) <= ord('Z') then res := res + chr(ord(s[i]) + 32) else
            res := res + s[i];
    end;
    tr := res;
end;

begin
    //assign(input, 'input.txt');
    readln(n);
    for i := 1 to n do begin
        readln(s);
        sm[i] := s;
        sm1[i] := tr(sm[i]);
        len1[i] := length(sm[i]);
    end;
    readln(w);
    w1 := tr(w);
    readln(letter);
    len := length(w);
    fillchar(conv, sizeof(conv), false);
    fillchar(used, sizeof(used), false);
    for i := 1 to len do begin
       if ord(w[i]) <= ord('Z') then  conv[i] := true;
    end;
    for i := 1 to len do
        cov[i] := 0;
    for i := 1 to n do begin
        for l := 1 to len - len1[i] + 1 do begin
            s1 := copy(w1, l, len1[i]);
            if s1 = sm1[i] then cov[l] := max(cov[l], len1[i]);
        end;
    end;
    for i := 1 to len do
        for j := 1 to cov[i] do
            used[i + j - 1] := true;
    res := '';
    for i := 1 to len do
        if used[i] then begin
            if w1[i] = letter then begin
                if letter <> 'a' then res := res + 'a' else res := res + 'b';
            end
            else res := res + letter
            end
        else
            res := res + w1[i];
    for i := 1 to len do
        if conv[i] then write(transf(res[i])) else write(res[i]);
    writeln;
    halt(0);
end.