program b;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var s1, s2, s3 : string;
    s1s, s2s, s3s : string;
    sp1, sp2, sp3, sp4, sp5, sp6 : string;
    curs, curss : string;
    res : array[1..1000] of integer;
    n, i, j : integer;

function ok(p : string): boolean;
begin
    if (p = sp1) or (p = sp2) or (p = sp3) or (p = sp4) or (p = sp5) or (p = sp6)
        then ok := true else ok := false;
end;

begin
    readln(s1);
    readln(s2);
    readln(s3);
    s1s := '';
    for i := 1 to length(s1) do
        if not((s1[i] = '_') or (s1[i] = '-') or (s1[i] = ';')) then begin
            if (ord(s1[i]) <= 90) then s1[i] := chr(ord(s1[i]) + 32);
            s1s := s1s + s1[i];
        end;
    s2s := '';
    for i := 1 to length(s2) do
        if not((s2[i] = '_') or (s2[i] = '-') or (s2[i] = ';')) then begin
            if (ord(s2[i]) <= 90) then s2[i] := chr(ord(s2[i]) + 32);
            s2s := s2s + s2[i];
        end;
    s3s := '';
    for i := 1 to length(s3) do
        if not((s3[i] = '_') or (s3[i] = '-') or (s3[i] = ';')) then begin
            if (ord(s3[i]) <= 90) then s3[i] := chr(ord(s3[i]) + 32);
            s3s := s3s + s3[i];
        end;
    sp1 := s1s + s2s + s3s;
    sp2 := s1s + s3s + s2s;
    sp3 := s2s + s1s + s3s;
    sp4 := s2s + s3s + s1s;
    sp5 := s3s + s1s + s2s;
    sp6 := s3s + s2s + s1s;
    readln(n);
    for i := 1 to n do begin
        readln(curs);
        curss := '';
        for j := 1 to length(curs) do
            if not((curs[j] = '_') or (curs[j] = '-') or (curs[j] = ';')) then begin
                if (ord(curs[j]) <= 90) then curs[j] := chr(ord(curs[j]) + 32);
                curss := curss + curs[j];
            end;
        if ok(curss) then res[i] := 1 else res[i] := 0;
    end;
    for i := 1 to n do
        if res[i] = 1then writeln('ACC') else writeln('WA');
end.