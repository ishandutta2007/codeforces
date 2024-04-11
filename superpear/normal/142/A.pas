var n,i,j,k,c:longint;
    max,min,e1,e2,e3:int64;
begin
  max:=0;
  min:=1000000000;
  min:=int64(min)*min;
  readln(n);
  for i:=1 to trunc(sqrt(n)) do
    if n mod i=0 then
      begin
        c:=n div i;
        for j:=1 to trunc(sqrt(c)) do
          if c mod j=0 then
            begin
              k:=c div j;
              e1:=int64(i+1)*(j+2)*(k+2);
              e2:=int64(i+2)*(j+1)*(k+2);
              e3:=int64(i+2)*(j+2)*(k+1);
              if e1>max then max:=e1;
              if e2>max then max:=e2;
              if e3>max then max:=e3;
              if e1<min then min:=e1;
              if e2<min then min:=e2;
              if e3<min then min:=e3;
            end;
      end;
  writeln(min-n,' ',max-n);
end.