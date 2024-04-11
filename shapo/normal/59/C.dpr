program Project2;

{$APPTYPE CONSOLE}

uses
  Math, SysUtils;

var k, i, num, why, j : integer;
    s, s1, s2 : string;
    alph : array[1..26] of boolean;
    res : array[1..100] of char;

begin
    fillchar(alph, sizeof(alph), false);
    readln(k);
    readln(s);
    s1 := '';
    s2 := '';
    for i := 1 to (length(s) + 1) div 2 do begin
        if (s[i] <> '?') xor (s[length(s) - i + 1] <> '?') then begin
            if s[i] <> '?' then s[length(s) - i + 1] := s[i] else
                s[i] := s[length(s) - i + 1];
        end;
        s1 := s1 + s[i];
        s2 := s2 + s[length(s) - i + 1];
    end;
    num := k;
    why := 0;
    for i := 1 to length(s1) do
        if s1[i] <> '?' then begin
            if not alph[ord(s[i]) - 96] then begin
                dec(num);
                alph[ord(s[i]) - 96] := true;
            end;
        end
        else inc(why);
    if (s1 <> s2) or (why < num) then begin
        writeln('IMPOSSIBLE');
        halt(0);
    end;
    i := length(s1);
    j := k;
    while (num <> 0) do begin
        while (alph[j]) do dec(j);
        while (s1[i] <> '?') do dec(i);
        s1[i] := chr(j + 96);
        alph[j] := true;
        dec(num);
    end;
    for i := 1 to length(s1) do begin
        if s1[i] = '?' then s1[i] := 'a';
        res[i] := s1[i];
        res[length(s) - i + 1] := s1[i];
    end;
    for i := 1 to length(s) do
        write(res[i]);
end.