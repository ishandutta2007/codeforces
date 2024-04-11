program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type vidget = record
    name : string;
    typ : longint;
    bord, space : int64;
    len, wid : int64;
    sp : array[0..1000] of longint;
end;

var n, i, num, x, y, code, j, j2 : longint;
    cur_ch : char;
    curs, name1, name2 : string;
    gets : array[1..1000] of vidget;
    used : array[1..1000] of boolean;
    buf : vidget;

function DFS(u : vidget; w : longint) : vidget;
var cur, cur1 : vidget;
    i : longint;
    j : int64;
begin
    cur := u;
    used[w] := true;
    if (cur.typ = 2) then begin
        if (cur.sp[0] <> 0) then begin
            cur.len := 2 * cur.bord;
            cur.wid := 2 * cur.bord;
            j := 0;
            for i := 1 to cur.sp[0] do begin
                if not used[cur.sp[i]] then
                    gets[cur.sp[i]] := DFS(gets[cur.sp[i]], cur.sp[i]);
                cur1 := gets[cur.sp[i]];
                if i <> 1 then cur.len := cur.len + cur.space;
                cur.len := cur.len + cur1.len;
                if j < cur1.wid then j := cur1.wid;
            end;
            cur.wid := cur.wid + j;
        end;
    end;
    if (cur.typ = 3) then begin
        if (cur.sp[0] <> 0) then begin
            cur.len := 2 * cur.bord;
            cur.wid := 2 * cur.bord;
            j := 0;
            for i := 1 to cur.sp[0] do begin
                if not used[cur.sp[i]] then
                    gets[cur.sp[i]] := DFS(gets[cur.sp[i]], cur.sp[i]);
                cur1 := gets[cur.sp[i]];
                if i <> 1 then cur.wid := cur.wid + cur.space;
                cur.wid := cur.wid + cur1.wid;
                if j < cur1.len then j := cur1.len;
            end;
            cur.len := cur.len + j;
        end;
    end;
    DFS := cur;
end;

begin
    //assign(input, 'input.txt');
    fillchar(used, sizeof(used), false);
    readln(n);
    num := 0;
    for i := 1 to n do begin
        curs := '';
        read(cur_ch);
        while (cur_ch <> ' ') and (cur_ch <> '.') do begin
            curs := curs + cur_ch;
            read(cur_ch);
        end;
        if (cur_ch = ' ') then begin
            name1 := curs;
            curs := '';
            if name1 = 'Widget' then begin
                read(cur_ch);
                while(cur_ch <> '(') do begin
                    curs := curs + cur_ch;
                    read(cur_ch);
                end;
                name2 := curs;
                read(cur_ch);
                curs := '';
                while (cur_ch <> ',') do begin
                    curs := curs + cur_ch;
                    read(cur_ch);
                end;
                val(curs, x, code);
                read(cur_ch);
                curs := '';
                while (cur_ch <> ')') do begin
                    curs := curs + cur_ch;
                    read(cur_ch);
                end;
                val(curs, y, code);
                readln;
                inc(num);
                gets[num].name := name2;
                gets[num].typ := 1;
                gets[num].len := x;
                gets[num].wid := y;
                gets[num].bord := 0;
                gets[num].space := 0;
                gets[num].sp[0] := 0;
            end;
            if name1 = 'HBox' then begin
                readln(name2);
                inc(num);
                gets[num].name := name2;
                gets[num].typ := 2;
                gets[num].len := 0;
                gets[num].wid := 0;
                gets[num].bord := 0;
                gets[num].space := 0;
                gets[num].sp[0] := 0;
            end;
            if name1 = 'VBox' then begin
                readln(name2);
                inc(num);
                gets[num].name := name2;
                gets[num].typ := 3;
                gets[num].len := 0;
                gets[num].wid := 0;
                gets[num].bord := 0;
                gets[num].space := 0;
                gets[num].sp[0] := 0;
            end;
        end
        else begin
            name1 := curs;
            curs := '';
            read(cur_ch);
            while (cur_ch <> '(') do begin
                curs := curs + cur_ch;
                read(cur_ch);
            end;
            if curs = 'pack' then begin
                curs := '';
                read(cur_ch);
                while (cur_ch <> ')') do begin
                    curs := curs + cur_ch;
                    read(cur_ch);
                end;
                name2 := curs;
                j := 1;
                while (j <= num) and (gets[j].name <> name2) do inc(j);
                readln;
                j2 := 1;
                while (j2 <= num) and (gets[j2].name <> name1) do inc(j2);
                inc(gets[j2].sp[0]);
                gets[j2].sp[gets[j2].sp[0]] := j;
            end;
            if curs = 'set_border' then begin
                curs := '';
                read(cur_ch);
                while (cur_ch <> ')') do begin
                    curs := curs + cur_ch;
                    read(cur_ch);
                end;
                val(curs, x, code);
                j2 := 1;
                while (j2 <= num) and (gets[j2].name <> name1) do inc(j2);
                gets[j2].bord := x;
                readln;
            end;
            if curs = 'set_spacing' then begin
                curs := '';
                read(cur_ch);
                while (cur_ch <> ')') do begin
                    curs := curs + cur_ch;
                    read(cur_ch);
                end;
                val(curs, x, code);
                j2 := 1;
                while (j2 <= num) and (gets[j2].name <> name1) do inc(j2);
                gets[j2].space := x;
                readln;
            end;
        end;
    end;
    for i := 1 to num do
        if not used[i] then gets[i] := DFS(gets[i], i);
    for i := 2 to num do
        for j := num downto i do
            if (gets[j].name < gets[j - 1].name) then begin
                buf := gets[j];
                gets[j] := gets[j - 1];
                gets[j - 1] := buf;
            end;
    for i := 1 to num do
        writeln(gets[i].name, ' ', gets[i].len, ' ', gets[i].wid);
    halt(0);
end.