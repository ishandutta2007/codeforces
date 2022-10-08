program E;
var a:array[1..1000,1..1000] of longint;
    n,i,j:longint;
begin
//  assign(input,'E.in');reset(input);
//  assign(output,'E.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    for j:=1 to n do a[i,j]:=1+(i+j-2)mod (n-1);
  for i:=1 to n do
    begin
      a[i,n]:=a[i,i];a[n,i]:=a[i,i];a[i,i]:=0;
    end;
  for i:=1 to n do
    begin
      for j:=1 to n-1 do write(a[i,j],' ');writeln(a[i,n]);
    end;
//  close(input);close(output);
end.