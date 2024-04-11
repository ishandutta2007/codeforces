program Project3;

{$APPTYPE CONSOLE}

uses
  Math, SysUtils;

var s, t : string;
    i, ind : integer;

begin
   readln(s);
   readln(t);
   if length(s) <> length(t) then writeln('NO') else begin
       i := 1;
       ind := 1;
       while (i <= length(s)) do begin
           if s[i] <> t[length(s) - i + 1] then ind := 0;
           inc(i);
       end;
       if ind = 0 then writeln('NO') else writeln('YES');
   end;
end.