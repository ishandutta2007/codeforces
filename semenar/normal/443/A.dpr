program Anton;
var i: integer;
arr, narr: string;
begin
readln(arr);
narr:='';
for i:=1 to length(arr) do
  begin
  if not ((arr[i] = '{') or (arr[i] = ',') or (arr[i] = ' ') or (arr[i] = '}')) then
    if pos(arr[i],narr) = 0 then narr:=narr+arr[i];
  end;
writeln(length(narr));
end.