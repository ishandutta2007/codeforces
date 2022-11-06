
program cf202_2;

var
    i,j,k,l,m,n:longint;
    a:array[1..9] of longint;
    f:boolean;

begin
  readln(n);
  l:=102039;
  k:=0;
  for i:= 1 to 9 do
    begin
      read(a[i]);
      if l>=a[i] then begin
        k:=i;
        l:=a[i];
      end;
    end;
  f:=true;
  m:=n div l;
  if m=0 then begin
    writeln('-1');
    halt;
  end;
  while f do
    begin
      f:=false;
      j:=9;
      while (j>k) and ((m-1)*l+a[j]>n) do
        dec(j);
      if j>k then begin
        f:=true;
        write(j);
        dec(m);
        n:=n-a[j];
      end;
    end;
  for i:= 1 to m do
    write(k);
  writeln
end.