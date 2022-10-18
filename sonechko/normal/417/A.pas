var x,y,n,m,i,j,k,l,min,r,c,d,s1,s2:longint;
  begin
    min:=maxlongint;
    read(c,d,n,m,k);
    if n*m-k<=0 then begin writeln('0'); halt; end;
    r:=n*m-k;
    for i:=0 to r do
     begin

       s1:=i*c;
       x:=i*n;
       y:=r-x;
       if y<0 then y:=0;
       s2:=y*d;
       if s1+s2<min then min:=s1+s2;
     end;
    writeln(min);
  end.