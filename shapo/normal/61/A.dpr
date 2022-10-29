program a;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var s1, s2, s : string;
    i : integer;

begin
    readln(s1);
    readln(s2);
    s := '';
    for i := 1 to length(s1) do
        if s1[i] <> s2[i] then s := s + '1' else s := s + '0';
    writeln(s);
end.