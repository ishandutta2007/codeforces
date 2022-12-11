var a, b, c: longint;
begin
//reset(input,'i.i');
//rewrite(output,'o.o');
read(a);
if a mod 36 = 35 then begin write((a+1) div 36, ' 0'); halt; end;
write(a div 36);
write(' ', (a mod 36 + 1) div 3);
end.