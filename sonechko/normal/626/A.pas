var n,m,i,j,k,ans,l,r,ll,rr:longint;
    s:string;
  begin
    readln(n);
    readln(s);
    for l:=1 to length(s) do
     begin
      ll:=0;
      rr:=0;
      for r:=l to length(s) do
       begin
        if (s[r]='L') then rr:=rr-1;
        if (s[r]='R') then rr:=rr+1;
        if (s[r]='U') then ll:=ll+1;
        if (s[r]='D') then ll:=ll-1;
        if (ll=0) and (rr=0) then ans:=ans+1;
      end;
     end;
    writeln(ans);
  end.