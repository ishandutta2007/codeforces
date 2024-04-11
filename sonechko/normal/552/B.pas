var n,m,i,j,k,ans,l,r:int64;
  begin
    read(n);
    ans:=0;
    l:=1;
    k:=1;
    r:=9;
    while true do
     begin
       if (n>=l) and (n<=r) then r:=n;
       ans:=ans+(r-l+1)*k;
       l:=l*10;
       r:=r*10+9;
       inc(k);
       if n<l then break;
     end;
    writeln(ans);
  end.