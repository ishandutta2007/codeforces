var x1,x2,x3,x4:longint;

function check(x1,x2,x3:longint):boolean;
  begin
    if (x1+x2>x3) and (x1+x3>x2) and (x2+x3>x1) then exit(true) else exit(false);
  end;

begin
  readln(x1,x2,x3,x4);
  if check(x1,x2,x3) or check(x1,x2,x4) or check(x1,x3,x4) or check(x2,x3,x4) then
    writeln('TRIANGLE')
  else
    if (x1+x2=x3) or (x1+x2=x4) or (x1+x3=x2) or (x1+x3=x4) or (x1+x4=x2) or (x1+x4=x3)
    or (x2+x3=x1) or (x2+x3=x4) or (x2+x4=x1) or (x2+x4=x3)
    or (x3+x4=x1) or (x3+x4=x2) then
      writeln('SEGMENT')
    else
      writeln('IMPOSSIBLE');
end.