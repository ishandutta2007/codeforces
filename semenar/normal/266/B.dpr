program GirlBoy;
var n, i, k, t: integer;
stack, stack_new: string;
begin
readln(n,t);
readln(stack);
for i:=1 to t do
  begin
  stack_new := stack;
  for k:=1 to n-1 do
    if (stack[k]='B') and (stack[k+1]='G') then
      begin
      stack_new[k]:='G';
      stack_new[k+1]:='B';
      end;
  stack:=stack_new;
  end;
writeln(stack);
end.