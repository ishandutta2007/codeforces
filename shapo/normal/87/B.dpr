program typecur;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type struct = record
    name : string;
    def : longint;
end;

var n, i, num : longint;
    sm : array[1..1000] of struct;
    curch : char;
    curs : string;

procedure add(u : string);
begin
    inc(num);
    sm[num].name := u;
    sm[num].def := 0;
end;

procedure typedef;
var s, s1, s2 : string;
    ch : char;
    i, i1, l, r, num1 : longint;
begin
    s := '';
    read(ch);
    while (ch = ' ') do read(ch);
    while (ch <> ' ') do begin
        s := s + ch;
        read(ch);
    end;
    read(ch);
    while (ch = ' ') do read(ch);
    s1 := ch;
    readln(s2);
    s1 := s1 + s2;
    i1 := 1;
    while (i1 <= num) and (sm[i1].name <> s1) do inc(i1);
    num1 := num;
    if i1 > num then begin
        add(s1);
        i1 := num;
    end;
    //num1 := num;
    l := 1;
    r := length(s);
    while (s[l] = '&') do inc(l);
    while (s[r] = '*') do dec(r);
    s2 := copy(s, l, r - l + 1);
    if s2 <> 'void' then begin
        i := 1;
        while (i <= num1) and (sm[i].name <> s2) do inc(i);
        if (i > num1) or (sm[i].def + length(s) - r < l - 1) then sm[i1].def := -100000 else
        sm[i1].def := sm[i].def  - (l - 1 + r - length(s));
    end
    else begin
        if length(s) - r < l - 1 then sm[i1].def := -100000
        else sm[i1].def := length(s) - r - l + 1;
    end;
end;

procedure typeof;
var s, s2 : string;
    ch : char;
    i, i1, l, r : longint;
begin
    read(ch);
    while ch = ' ' do read(ch);
    s := ch;
    readln(s2);
    s := s + s2;
    i := 1;
    l := 1;
    r := length(s);
    while (s[l] = '&') do inc(l);
    while (s[r] = '*') do dec(r);
    s2 := copy(s, l, r - l + 1);
    if s2 = 'void' then begin
        if length(s) - r < l - 1 then writeln('errtype') else begin
            write('void');
            for i1 := 1 to length(s) - r - l + 1 do
                write('*');
            writeln;
        end;
    end
    else begin
        while (i <= num) and (sm[i].name <> s2) do inc(i);
        if (i > num) or (sm[i].def + length(s) - r < l - 1) then writeln('errtype') else begin
            write('void');
            for i1 := 1 to (sm[i].def - (l - 1 + r - length(s))) do
                write('*');
            writeln;
        end;
    end;
end;

begin
    //assign(input, 'b.in');
    readln(n);
    num := 0;
    for i := 1 to n do begin
        curs := '';
        read(curch);
        while (curch = ' ') do read(curch);
        while (curch <> ' ') do begin
            curs := curs + curch;
            read(curch);
        end;
        if curs = 'typedef' then typedef else typeof;
    end;
    halt(0);
end.