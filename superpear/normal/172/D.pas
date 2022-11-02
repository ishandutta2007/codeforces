var i,e,j,n,s:longint;
    ans:int64;
    a:array[0..10000000] of longint;
begin
  for i:=1 to 10000000 do a[i]:=1;
  for i:=1 to 4000 do
    begin
      e:=i*i;
      for j:=1 to (10000000 div e) do
        a[e*j]:=e;
    end;
  readln(s,n);
  ans:=0;
  for i:=s to s+n-1 do
    ans:=ans+int64(i div a[i]);
  writeln(ans);
end.