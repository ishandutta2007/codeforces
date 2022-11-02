var st:ansistring;
    s,stack:array[0..200000] of char;
    ls,i,top:longint;
begin
  readln(st);
  ls:=length(st);
  for i:=1 to ls do s[i]:=st[i];
  top:=0;
  for i:=1 to ls do
    begin
      while (top>0) and (st[i]>stack[top]) do dec(top);
      inc(top);
      stack[top]:=st[i];
    end;
  for i:=1 to top do write(stack[i]);writeln;
end.