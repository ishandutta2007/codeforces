var m,n,i,j,s,max:longint;
    ch:char;
    a:array[0..2000,0..2000] of longint;
    ok:array[0..2000] of longint;
begin
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(ch);
          a[i,j]:=ord(ch)-48;
        end;
      readln;
    end;
  fillchar(ok,sizeof(ok),0);
  for i:=1 to m do
    begin
      max:=0;
      for j:=1 to n do
        if a[j,i]>max then max:=a[j,i];
      for j:=1 to n do
        if a[j,i]=max then ok[j]:=1;
    end;
  s:=0;
  for i:=1 to n do s:=s+ok[i];
  writeln(s);
end.