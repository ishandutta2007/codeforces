var a1,a2,a3,n,i,x:longint;
begin
    readln(n);
    a1:=0;a2:=0;a3:=0;
    for i:=1 to n do
        begin
            read(x);
            if(x=1)then inc(a1) else
            if(x=2)then inc(a2) else
            if(x=3)then inc(a3);
        end;
    if(a1>=a2)and(a1>=a3)then writeln(a2+a3) else
    if(a2>=a1)and(a2>=a3)then writeln(a1+a3) else
    if(a3>=a1)and(a3>=a2)then writeln(a1+a2);
end.