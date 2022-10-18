var n,m,p,i,j,k,l:longint;
    x,y:array[1..1000]of longint;
  begin
    read(m);
    for i:=1 to m do
     begin
       k:=0;
       read(n,p);
       j:=1;
       l:=2;
       fillchar(x,sizeof(x),0);
       fillchar(y,sizeof(y),0);
       while  k<n*2+p do
        begin
          inc(k);
          x[k]:=j;
          y[k]:=l;
          if l<>n then inc(l) else begin inc(j); l:=j+1; end;
        end;
       for j:=1 to k do
        writeln(x[j],' ',y[j]);
     end;
  end.