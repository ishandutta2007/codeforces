program A;
var c1,c2,c3,c4,c5,c6,c7,c8,c9:char;
begin
  readln(c1,c2,c3);readln(c4,c5,c6);readln(c7,c8,c9);
  if(c1=c9)and(c2=c8)and(c3=c7)and(c4=c6)then writeln('YES')else writeln('NO');
end.