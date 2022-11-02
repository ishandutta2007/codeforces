var s:string;k:longint;

begin
  assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);

  readln(s);
  readln(k);
  if (s='front') and (k=1) then writeln('L');
  if (s='front') and (k=2) then writeln('R');
  if (s='back') and (k=1) then writeln('R');
  if (s='back') and (k=2) then writeln('L');

  close(input);
  close(output);
end.