program Checkmate;
var pos_white, pos_black, i, k: integer;
symbol: string;
white, black: string;
begin
white:='-P---NB--R-------Q';
black:='-p---nb--r-------q';
pos_white:=0;
pos_black:=0;
for i:=1 to 8 do
  begin
  readln(symbol);
  for k:=1 to 8 do
    begin
    pos_white:=pos_white+(pos(symbol[k],white) div 2);
    pos_black:=pos_black+(pos(symbol[k],black) div 2);
    end;
  end;
if (pos_white > pos_black) then writeln('White') else if (pos_white = pos_black) then writeln('Draw') else writeln('Black');
end.