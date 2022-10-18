var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n);
    if n<4 then begin writeln('NO'); halt; end;
    writeln('YES');
    if n mod 2=0 then
     begin
       while n>4 do
        begin
          writeln(n,' - ',n-1,' = 1');
          writeln('1 * 1 = 1');
          dec(n,2);
        end;
       writeln('4 * 3 = 12');
       writeln('12 * 2 = 24');
       writeln('24 * 1 = 24');
     end;
    if n mod 2=1 then
     begin
       while n>5 do
        begin
          writeln(n,' - ',n-1,' = 1');
          writeln('1 * 1 = 1');
          dec(n,2);
        end;
       writeln('5 * 4 = 20');
       writeln('20 + 3 = 23');
       writeln('23 + 2 = 25');
       writeln('25 - 1 = 24');
     end;
  end.