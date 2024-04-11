var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n,m);
    while (n>0) and (m>0) do
     begin
       if (n=1) and (m=1) then break;
       if (n<m) then begin n:=n+1; m:=m-2; end else
       begin n:=n-2; m:=m+1; end;
       ans:=ans+1;
     end;
    writeln(ans);

  end.