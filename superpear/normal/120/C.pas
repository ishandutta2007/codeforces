var m,n,i,s,x:longint;

begin
  assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);
  readln(n,m);
  s:=0;
  for i:=1 to n do
    begin
      read(x);
      if x>=3*m then s:=s+x-3*m else s:=s+x mod m;
    end;
  writeln(s);
  close(input);
  close(output);
end.