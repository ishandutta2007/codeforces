program A_;
var a:array[1..4] of longint;
    i,j,k:longint;
begin
//  assign(input,'A.in');reset(input);
//  assign(output,'A.out');rewrite(output);
  readln(a[1],a[2],a[3],a[4]);
  for i:=1 to 3 do
    for j:=i+1 to 4 do
      if a[i]>a[j] then
        begin
          k:=a[i];a[i]:=a[j];a[j]:=k;
        end;
  for i:=1 to 2 do
    for j:=i+1 to 3 do
      for k:=j+1 to 4 do
        if a[i]+a[j]>a[k] then
          begin
            writeln('TRIANGLE');
//            close(input);close(output);
            halt;
          end;
  for i:=1 to 2 do
    for j:=i+1 to 3 do
      for k:=j+1 to 4 do
        if a[i]+a[j]=a[k] then
          begin
            writeln('SEGMENT');
//            close(input);close(output);
            halt;
          end;
  writeln('IMPOSSIBLE');
//  close(input);close(output);
end.