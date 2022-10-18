var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..50]of longint;
  begin
    read(n);
    for i:=1 to n*n do
     begin
       read(l,r);
       if (a[l]=0) and (b[r]=0) then begin a[l]:=1; b[r]:=1; write(i,' '); end;
     end;
    writeln;
  end.