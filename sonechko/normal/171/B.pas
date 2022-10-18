var c,a,b,i:longint;
  begin
    read(a);
    b:=0;
    for i:=1 to a-1 do
     b:=b+i*2;
    c:=a-2;
    for i:=a+2+c to a*2+c do
     b:=b+i*2;
    b:=b+a+1+c;
    writeln(b);
  end.