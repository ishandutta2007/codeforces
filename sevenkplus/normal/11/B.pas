program B;
var n,i:longint;
begin
//  assign(input,'B.in');reset(input);
//  assign(output,'B.out');rewrite(output);
  readln(n);
  if n<0 then n:=-n;i:=0;
  while (n>0) or odd(n) do
    begin
      inc(i);dec(n,i);
    end;
  writeln(i);
//  close(input);close(output);
end.