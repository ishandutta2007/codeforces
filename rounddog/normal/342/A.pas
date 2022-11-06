
program cf199_1;

var
    i,k,j,n,b,c,d:longint;
    a:array[0..7] of longint;

begin
  repeat
    readln(n);
  until n mod 3=0;
  fillchar(a,sizeof(a),0);
  for i:= 1 to n do
    begin
      read(j);
      inc(a[j]);
    end;
  readln;
  k:= n div 3;
  if (a[1]=k) and (a[2]+a[3]=k) and (a[4]+a[6]=k) and (a[4]<=a[2]) then begin
    for j:= 1 to a[4] do
      writeln('1 2 4');
    for j:= 1 to a[2]-a[4] do
      writeln('1 2 6');
    for j:= 1 to a[3] do
      writeln('1 3 6');
  end
  else writeln(-1);
end.