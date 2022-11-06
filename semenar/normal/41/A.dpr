program Ukrainian;
var i: integer;
stroke1, stroke2, google_translator: string;
begin
readln(stroke1);
readln(stroke2);
if (length(stroke1) <> length(stroke2)) then writeln('NO')
else
  begin
  google_translator := 'YES';
  for i:=1 to length(stroke1) do
    if stroke1[i] <> stroke2[length(stroke2)+1-i] then google_translator := 'NO';
  writeln(google_translator);
  end;
end.