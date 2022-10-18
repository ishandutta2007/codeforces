var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n,m);
    for i:=1 to n do
     begin
       read(j,k);
       if j>k then begin ans:=j; j:=k; k:=ans; end;
       if i=1 then begin l:=j; r:=k; end else
       begin if j>l then l:=j; if k<r then r:=k; end;
     end;
    if l>r then writeln(-1) else
    if (m>=l) and (m<=r) then writeln(0) else
    if m<l then writeln(l-m) else writeln(m-r);
  end.