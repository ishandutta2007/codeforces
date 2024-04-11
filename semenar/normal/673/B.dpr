program Round3div2;
var arr: array [1..100000] of integer;
n, m, a, b, i, can_do, max2, min1: integer;

begin
  readln(n, m);
  can_do := 1;
  for i:=1 to n do
    arr[i] := 0;
  for i:=1 to m do
    begin
    readln(a,b);
    if (a<b) then begin
      if (arr[a]=1) then can_do:=0;
      if (arr[b]=2) then can_do:=0;
      arr[a] := 2;
      arr[b] := 1;
      end
    else begin
      if (arr[a]=2) then can_do:=0;
      if (arr[b]=1) then can_do:=0;
      arr[a] := 1;
      arr[b] := 2;
      end;
    end;
   if (can_do = 0) then writeln('0')
   else if (m>0) then begin
    for i:=1 to n do
      if (arr[i]=2) then max2:=i;
    for i:=n downto 1 do
      if (arr[i]=1) then min1:=i;
    if (max2 > min1) then writeln('0') else writeln(min1-max2);
   end
      else writeln(n-1);
end.