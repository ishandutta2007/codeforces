var f:array[0..20,0..3,0..20] of longint;
    n,t,tt,i,j,k,l:longint;
begin
  fillchar(f,sizeof(f),0);
  f[0,0,0]:=1;f[0,1,0]:=1;f[0,2,0]:=1;
  for i:=1 to 20 do
    for j:=0 to 3 do
      for k:=0 to 19 do
        for l:=0 to 3 do
          if ((i=1) and (j>l)) or ((i>1) and (j<>l)) then
            if (j<l)=odd(k) then inc(f[i,j,k],f[i-1,l,k]) else inc(f[i,j,k+1],f[i-1,l,k]);
  tt:=1;
  for tt:=1 to tt do
    begin
      readln(n,t);
      writeln(f[n-1,0,t+t-1]+f[n-1,1,t+t-1]+f[n-1,2,t+t-1]+f[n-1,3,t+t-1]);
    end;
end.