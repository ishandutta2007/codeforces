var n,m,j,k,ans,l,r:int64;  i:longint;
  begin
    read(n);
    l:=1;
    for i:=1 to 100 do
     begin
       l:=l*3;
       if n mod l<>0 then break;
     end;
    writeln(n div l+1);
  end.