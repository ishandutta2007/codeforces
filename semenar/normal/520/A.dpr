program Pangramm;
var i, n: integer;
str, alphabet: string;

procedure standartize(var s:string);
var i:integer;
begin
for i:=1 to length(s) do
  if ord(s[i]) > 96 then s[i]:=chr(ord(s[i])-32);
end;

begin
readln(n);
readln(str);
standartize(str);
alphabet:='';
for i:=1 to n do
  if pos(str[i],alphabet)=0 then alphabet:=alphabet+str[i];
if length(alphabet)=26 then writeln('YES') else writeln('NO');
end.