program GrammarNazi;
var big, small, i: integer;
str: string;

procedure to_upper(var s:string);
var i:integer;
begin
for i:=1 to length(s) do
  if ord(s[i]) > 96 then s[i]:=chr(ord(s[i])-32);
end;

procedure to_lower(var s:string);
var i:integer;
begin
for i:=1 to length(s) do
  if ord(s[i]) < 97 then s[i]:=chr(ord(s[i])+32);
end;

begin
readln(str);
big:=0;
small:=0;
for i:=1 to length(str) do
  if ord(str[i]) > 96 then small:=small+1 else big:=big+1;
if big>small then to_upper(str) else to_lower(str);
writeln(str);
end.