program Podarok;
var output, i: integer;
str1, str2: string;

procedure to_lower(var str0: string);
var i: integer;
begin
for i:=1 to length(str0) do
  if ord(str0[i]) < 97 then str0[i] := chr(ord(str0[i])+32);
end;

function max(a, b: integer): integer;
begin
if a>b then max := a else max := b;
end;

begin
readln(str1);
readln(str2);
to_lower(str1);
to_lower(str2);
output := 0;
i := 1;
while (output = 0) and (max(length(str1),length(str2))>=i) do
  begin
  if length(str1) >= i
    then if length(str2) >= i 
      then if ord(str1[i]) > ord(str2[i]) 
        then output := 1 
        else if ord(str1[i]) < ord(str2[i])
          then output := -1
          else
      else output := 1
    else if length(str2) > i then output := -1;
  i := i+1;
  end;
writeln(output);
end.