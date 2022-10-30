program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var s, s1 : string;
    i : longint;

function upase(x:char):char;
begin
    if ord(x)<ord('a') then upase:=chr(ord(x)+32) else upase :=x;
end;

procedure obr(x:char);
begin
    if(x<>'a')and(x<>'o')and(x<>'y')and(x<>'e')and(x<>'u')and(x<>'i')then
        s1 := s1+'.'+x;
end;

begin
    readln(s);
    s1 := '';
    for i:=1 to length(s) do begin
        s[i]:=upase(s[i]);
        obr(s[i]);
    end;
    writeln(s1);
    halt(0);
end.