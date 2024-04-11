
program cf202_1;

var
    i,j,k,l,m,n:longint;
    a,b:longint;

begin
  readln(n);
  a:=0;
  b:=0;
  for i:= 1 to n do
    begin
      read(m);
      if m=100 then begin
        if (a*b>0) then begin
          dec(a);
          dec(b);
        end
        else if a>2 then
          a:=a-3
        else begin
          writeln('NO');
          halt;
        end;
      end
      else if m=50 then begin
        if a=0 then begin
          writeln('NO');
          halt;
        end
        else begin
          dec(a);
          inc(b);
        end;
      end
      else inc(a);
    end;
  readln;
  writeln('YES');
end.