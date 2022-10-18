var n,m,i,j,k,ans,l,r,d:int64;
  begin
    read(n);
    d:=2;
    ans:=1;
    while (d*d<=n) do
     if n mod d=0 then
      begin
        k:=1;
        n:=n div d;
      end else
      begin
        if k=1 then ans:=ans*d;
        k:=0;
        inc(d);
      end;
    if k=1 then ans:=ans*d;
    if (n<>d) or (k=0) then ans:=ans*n;
    writeln(ans);
  end.