var c,x,f:array[0..3001] of int64;
    n,i,j:longint;
    p,t:int64;
begin
  readln(n);
  for i:=1 to n do readln(x[i],c[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if x[i]>x[j] then
        begin
          t:=x[i];x[i]:=x[j];x[j]:=t;
          t:=c[i];c[i]:=c[j];c[j]:=t;
        end;
  f[0]:=0;
  for i:=1 to n do
    begin
      for j:=i-1 downto 0 do
        begin
          if j=i-1 then p:=0 else
            begin
              inc(p,int64(i-j-1)*int64(x[j+2]-x[j+1]));
            end;
          t:=f[j]+c[j+1]+p;
          if (j=i-1) or (t<f[i]) then f[i]:=t;
        end;
    end;
  writeln(f[n]);
end.