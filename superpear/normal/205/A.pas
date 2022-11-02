var n,i,mink,min:longint;
    a:array[0..200000] of longint;
begin
  readln(n);
  min:=maxlongint;
  for i:=1 to n do
    begin
      read(a[i]);
      if a[i]<min then min:=a[i];
    end;
  mink:=-1;
  for i:=1 to n do
    if a[i]=min then
      begin
        if mink<>-1 then
          begin
            writeln('Still Rozdil');
            halt;
          end;
        mink:=i;
      end;
  writeln(mink);
end.