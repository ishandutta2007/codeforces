var s:string;
    n,m,i,j,k,ans,l,r:longint;
  begin
    for j:=1 to 8 do
     begin
       readln(s);
       for i:=2 to length(s) do
        if s[i]=s[i-1] then begin writeln('NO'); halt; end;
     end;
    writeln('YES');
  end.