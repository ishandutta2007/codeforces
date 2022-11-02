var n,i,ch,e:longint;
    a,hash:array[0..1000000] of longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
    begin
      read(ch);
      hash[ch]:=i;
    end;
  for i:=1 to n do a[i]:=hash[a[i]];
  e:=1;
  while a[e+1]>a[e] do inc(e);
  writeln(n-e);
end.