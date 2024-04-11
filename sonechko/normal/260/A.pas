var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n,m,k);
    l:=-1;
    for i:=0 to 9 do
     if (n*10+i) mod m=0 then l:=n*10+i;
    if l=-1 then begin writeln('-1'); halt; end;
    write(l);
    for i:=1 to k-1 do
     write(0);
    writeln;
  end.