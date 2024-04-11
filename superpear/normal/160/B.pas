var n,i,j,flag:longint;
    ch:char;
    a,b:array[0..10000] of longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(ch);
      a[i]:=ord(ch)-48;
    end;
  for i:=1 to n do
    begin
      read(ch);
      b[i]:=ord(ch)-48;
    end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then swap(a[i],a[j]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if b[i]>b[j] then swap(b[i],b[j]);
  flag:=1;
  for i:=1 to n do
    if a[i]<=b[i] then
      begin
        flag:=0;
        break;
      end;
  if flag=1 then writeln('YES') else
    begin
      flag:=1;
      for i:=1 to n do
        if a[i]>=b[i] then
          begin
            flag:=0;
            break;
          end;
      if flag=1 then writeln('YES') else writeln('NO');
    end;
end.