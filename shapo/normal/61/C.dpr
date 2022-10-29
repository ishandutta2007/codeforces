program c;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var a, b, i, numr, curr, pr : integer;
    num, cur, p : int64;
    s, s1 : string;
    r : boolean;
    res : array[0..50] of integer;

begin
    readln(s);
    s1 := '';
    i := 1;
    while (s[i] <> ' ') do begin
        s1 := s1 + s[i];
        inc(i);
    end;
    inc(i);
    a := strtoint(s1);
    s1 := '';
    if s[i] = 'R' then r := true else r := false;
    if not r then begin
        while(i <= length(s)) do begin
            s1 := s1 + s[i];
            inc(i);
        end;
        b := strtoint(s1);
    end;
    readln(s);
    while (length(s) > 1) and (s[1] = '0') do delete(s, 1, 1);
    if r then begin
        numr := 0;
        curr := 1;
        for i := length(s) downto 1 do begin
            if (ord(s[i]) <= 57) then pr := strtoint(s[i]) else pr := 10 + ord(s[i]) - ord('A');
            numr := numr + (pr * curr);
            if curr < 1000000000 then curr := curr * a;
        end;
        case (numr div 1000) of
            1 : write('M');
            2 : write('MM');
            3 : write('MMM');
        end;
        case (numr mod 1000) div 100 of
            1 : write('C');
            2 : write('CC');
            3 : write('CCC');
            4 : write('CD');
            5 : write('D');
            6 : write('DC');
            7 : write('DCC');
            8 : write('DCCC');
            9 : write('CM');
        end;
        case (numr mod 100) div 10 of
            1 : write('X');
            2 : write('XX');
            3 : write('XXX');
            4 : write('XL');
            5 : write('L');
            6 : write('LX');
            7 : write('LXX');
            8 : write('LXXX');
            9 : write('XC');
        end;
        case (numr mod 10) of
            1 : write('I');
            2 : write('II');
            3 : write('III');
            4 : write('IV');
            5 : write('V');
            6 : write('VI');
            7 : write('VII');
            8 : write('VIII');
            9 : write('IX');
        end;
    end
    else begin
        num := 0;
        cur := 1;
        for i := length(s) downto 1 do begin
            if (ord(s[i]) <= 57) then p := strtoint(s[i]) else p := 10 + ord(s[i]) - ord('A');
            num := num + (p * cur);
            if cur < 10000000000000000 then cur := cur * a;
        end;
        res[0] := 0;
        while (num <> 0) do begin
            inc(res[0]);
            res[res[0]] := num mod b;
            num := num div b;
        end;
        if res[0] = 0 then writeln('0');
        for i := res[0] downto 1 do begin
            if res[i] >= 10 then write(chr(res[i] - 10 + ord('A'))) else write(chr(res[i] + ord('0')));
        end;
    end;
end.