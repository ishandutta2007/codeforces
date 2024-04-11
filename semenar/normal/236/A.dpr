program Chatbot;
var chathum, symbols: string;
i: integer;
begin
readln(chathum);
symbols := '';
for i:=1 to length(chathum) do
  if pos(chathum[i],symbols) = 0 then symbols := symbols+chathum[i];
if (length(symbols) mod 2) = 0 then writeln('CHAT WITH HER!') else writeln('IGNORE HIM!');
end.