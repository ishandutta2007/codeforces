var a,b,c,i,l,r:longint;
  begin
    read(l,r);
    for i:=1 to 6 do
     if abs(i-l)<abs(i-r) then inc(a) else
     if abs(i-l)=abs(i-r) then inc(b) else inc(c);
    writeln(a,' ',b,' ',c);
  end.