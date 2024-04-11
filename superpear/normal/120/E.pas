var tt,gb,n:longint;

begin
  assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);
  readln(tt);
  for gb:=1 to tt do
    begin
      readln(n);
      writeln(1-n mod 2);
    end;
  close(input);
  close(output);
end.