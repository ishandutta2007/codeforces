program C_;
var c:array[1..9] of longint;
    i,a1,a2:longint;
    ch:char;
function t(a,b,c,d:longint):boolean;
  begin
    exit((a=b) and (b=c) and (c=d));
  end;
function win(p:longint):boolean;
  begin
    exit(t(c[1],c[2],c[3],p) or t(c[1],c[5],c[9],p) or t(c[1],c[4],c[7],p) or
    t(c[2],c[5],c[8],p) or t(c[3],c[5],c[7],p) or t(c[3],c[6],c[9],p) or
    t(c[4],c[5],c[6],p) or t(c[7],c[8],c[9],p));
  end;
procedure f(s:string);
  begin
    writeln(s);
//    close(input);close(output);halt;
  end;
begin
//  assign(input,'C.in');reset(input);
//  assign(output,'C.out');rewrite(output);
  a1:=0;a2:=0;
  for i:=1 to 9 do
    begin
      read(ch);
      if ch='X' then begin c[i]:=1;inc(a1);end else
      if ch='0' then begin c[i]:=2;inc(a2);end else c[i]:=0;
      if i mod 3=0 then readln;
    end;
  if (a1<a2) or(a1-a2>1) or ((a1-a2=1) and win(2)) or ((a1=a2) and win(1)) then f('illegal') else
  if win(1) then f('the first player won') else
  if win(2) then f('the second player won') else
  if a1+a2=9 then f('draw') else
  if a1=a2 then f('first') else f('second');
end.