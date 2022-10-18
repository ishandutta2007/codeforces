uses math;
var i,j,k,ans,l,r,n,m,min1,min2,min3,max1,max2,max3:longint;
  begin
    read(n,min1,max1,min2,max2,min3,max3);
    for i:=max1 downto min1 do
     begin
       k:=n-i;
       l:=min2;
       r:=max2;
       while (r-l>1) do
        begin
          m:=(r+l) div 2;
          if (k-m>=min3) and (k-m<=max3) then l:=m else
          if (k-m>max3) then l:=m else r:=m;
        end;
       //if (i=2) then writeln(r,' ',l);
       if (k-r>=min3) and (k-r<=max3) then
        begin writeln(i,' ',r,' ',n-i-r); halt; end;
       if (k-l>=min3) and (k-l<=max3) then
        begin writeln(i,' ',l,' ',n-i-l); halt; end;
     end;
  end.