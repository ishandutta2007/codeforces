var n,x,i,j,k,all:longint;
    a:array[0..10000] of longint;
procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;
begin
  readln(n,x);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then swap(a[i],a[j]);
  if a[(n+1) div 2]=x then writeln(0) else
    begin
      if a[(n+1) div 2]<x then
        begin
          k:=n+1;
          for j:=1 to n do
            if a[j]>=x then
              begin
                k:=j;
                break;
              end;
          all:=k*2-1;
          writeln(all-n);
        end
      else
        begin
          k:=0;
          for j:=n downto 1 do
            if a[j]<=x then
              begin
                k:=j;
                break;
              end;
          all:=n-k*2;
          writeln(all);
        end;
    end;
end.