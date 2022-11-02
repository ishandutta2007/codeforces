var m,n,k,i,ssc:longint;
    a:array[0..1000] of longint;
    ans:extended;

begin
  readln(n,m,k);
  ssc:=0;
  for i:=1 to m do
    begin
      read(a[i]);
      inc(ssc,a[i]);
    end;
  if ssc<n then
    begin
      writeln('-1');
      halt;
    end;
  if ssc-(a[k]-1)<n then
    begin
      writeln('1');
      halt;
    end;
  ans:=1;
  dec(a[k]);
  dec(ssc);
  for i:=1 to n-1 do
    ans:=ans*(ssc-i+1-a[k])/(ssc-i+1);
  writeln(1-ans:0:10);
end.