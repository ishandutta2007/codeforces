var n,i,e,flag:longint;
    s:array[0..100000] of string[30];
begin
  readln(n);
  for i:=1 to n do
    readln(s[i]);
  e:=0;
  repeat
    flag:=1;
    for i:=2 to n do
      if s[i][e+1]<>s[i-1][e+1] then
        begin
          flag:=0;
          break;
        end;
    if flag=0 then break;
    inc(e);
  until e=length(s[1]);
  writeln(e);
end.