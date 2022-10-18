var n,m,k,i,j,l,r:longint;
    s:string;
  begin
    readln(n,l);
    readln(s);
    for j:=1 to l do
     begin
       i:=1;
       while i<=n-1 do
        if s[i]<s[i+1] then
         begin
           s[i+1]:='B';
           s[i]:='G';
           i:=i+2;
         end else i:=i+1;
     end;
    writeln(s);
  end.