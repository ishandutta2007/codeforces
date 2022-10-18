var a,b,g:int64;
    i,j,n:longint;
  begin
    read(a,b,n);
    for i:=-1000 to 1000 do
     begin
       g:=1;
       for j:=1 to n do
        begin
          g:=g*i;
          if abs(g)>abs(b) then break;
        end;
       if a*g=b then
        begin
          writeln(i);
          halt;
        end;
     end;
    writeln('No solution');
  end.