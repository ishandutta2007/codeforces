program FastestXOR;
var i: integer;
str1, str2, ans: string;
begin
readln(str1);
readln(str2);
ans:='';
for i:=1 to length(str1) do
  if (str1[i] <> str2[i]) then ans:=ans+'1' else ans:=ans+'0';
writeln(ans);
end.