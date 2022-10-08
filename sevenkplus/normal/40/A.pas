var x,y:longint;
    d:extended;
procedure e(s:string);
  begin
    writeln(s);halt;
  end;
begin
  readln(x,y);
  if (x=0) or (y=0) then e('black');
  d:=sqrt(sqr(x)+sqr(y));
  if abs(round(d)-d)<1e-8 then e('black');
  if (x>0) xor (y>0) then
    if odd(trunc(d)) then e('black') else e('white') else
    if odd(trunc(d)) then e('white') else e('black');
end.