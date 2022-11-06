program Limak;
var mode: string;
sweets, tmp: integer;
begin
read(tmp);
readln(mode);
if (mode = ' of week')
  then if (tmp > 4) and (tmp < 7) then sweets := 53 else sweets := 52
  else if (tmp < 30) then sweets := 12 else if (tmp < 31) then sweets := 11 else sweets := 7;
writeln(sweets);
end.