var k,i,j,e,s:longint;
    a:array[0..16] of longint;
begin
  readln(k);
  for i:=1 to 12 do read(a[i]);
  for i:=1 to 11 do
    for j:=i+1 to 12 do
      if a[i]<a[j] then
        begin
          s:=a[i];a[i]:=a[j];a[j]:=s;
        end;
  e:=0;
  while (e<12) and (k>0) do
    begin
      inc(e);
      k:=k-a[e];
    end;
  if k>0 then writeln(-1) else writeln(e);
end.