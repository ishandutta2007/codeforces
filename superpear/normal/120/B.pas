var m,n,i,s:longint;
    a:array[0..1000000] of longint;

begin
  assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);

  readln(n,m);
  for i:=1 to n do
    read(a[i]);
  s:=m;
  while a[s]=0 do
    begin
      s:=s+1;
      if s>n then s:=1;
    end;
  writeln(s);

  close(input);
  close(output);
end.