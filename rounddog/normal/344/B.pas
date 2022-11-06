
program cf200_2;

var
    a,b,c,s:longint;

begin
  readln(a,b,c);
  if (a+b+c) mod 2<>0 then begin
    writeln('Impossible');
    halt
  end
  else begin
    s:=(a+b+c) div 2;
    if (s>a) and (s>b) and (s>c) then
      writeln(s-c,' ',s-a,' ',s-b)
    else if (s=a) and (s>b) and (s>c) then
      writeln(s-c,' ',s-a,' ',s-b)
    else if (s>a) and (s=b) and (s>c) then
      writeln(s-c,' ',s-a,' ',s-b)
    else if (s>a) and (s>b) and (s=c) then
      writeln(s-c,' ',s-a,' ',s-b)
    else
      writeln('Impossible');
  end;
end.