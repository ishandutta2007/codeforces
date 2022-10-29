program task;

{$APPTYPE CONSOLE} {$R+,S+,O-,Q+,I+}

uses
  Math,
  SysUtils;

type typ = record
    n, n1 : longint;
end;

var s, s1, ss : string;
    prm, prw, sum, suw, glm, glw : string;
    cur : array[1..100000] of typ;
    i, l, num, st : longint;

procedure read_word(var u : longint);
begin
    while (u <= l) and (s1[u] <> ' ') do begin
        ss := ss + s1[u];
        inc(u);
    end;
end;

procedure obr(s : string; x : longint);
var a, b, c, d : string;
begin
    a := copy(s, 1, 3);
    b := copy(s, 1, 4);
    c := copy(s, 1, 5);
    d := copy(s, 1, 6);
    {writeln(a);
    writeln(b);
    writeln(c);
    writeln(d);}
    cur[x].n := 0;
    cur[x].n1 := 0;
    if a = sum then begin
        cur[x].n := 2;
        cur[x].n1 := 1;
    end;
    if b = suw then begin
        cur[x].n := 2;
        cur[x].n1 := 2;
    end;
    if b = prm then begin
        cur[x].n := 3;
        cur[x].n1 := 1;
    end;
    if c = prw then begin
        cur[x].n := 3;
        cur[x].n1 := 2;
    end;
    if d = glm then begin
        cur[x].n := 1;
        cur[x].n1 := 1;
    end;
    if d = glw then begin
        cur[x].n := 1;
        cur[x].n1 := 2;
    end;
end;

begin
    //assign(input, 'input.txt');
    readln(s);
    l := length(s);
    s1 := '';
    for i := l downto 1 do
        s1 := s1 + s[i];
    prm := 'soil';
    prw := 'alail';
    sum := 'rte';
    suw := 'arte';
    glm := 'sitini';
    glw := 'setini';
    num := 0;
    i := 1;
    while (i <= l) do begin
        ss := '';
        read_word(i);
        inc(num);
        inc(i);
        obr(ss, num);
    end;
    if num = 1 then
        if cur[1].n = 0 then writeln('NO') else writeln('YES')
    else begin
        l := cur[1].n1;
        st := 0;
        for i := 1 to num do begin
            if st = 0 then begin
                if cur[i].n = 1 then st := 0;
                if cur[i].n = 2 then st := 1;
                if (cur[i].n = 3) or (cur[i].n = 0) or (l <> cur[i].n1) then begin
                    writeln('NO');
                    halt(0);
                end;
            end
            else begin
                if st = 1 then begin
                    if (cur[i].n = 3) and (l = cur[i].n1) then st := 2
                    else begin
                        writeln('NO');
                        halt(0);
                    end;
                end
                else begin
                    if st = 2 then begin
                        if (cur[i].n = 3) and (l = cur[i].n1) then st := 2
                        else begin
                            writeln('NO');
                            halt(0);
                        end;
                    end;
                end;
            end;
        end;
        if (l <> 0) and (st >= 1) then writeln('YES') else writeln('NO');
    end;
    halt(0);
end.