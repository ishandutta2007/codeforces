var n,m,i,j,k,ans,l,r:longint;
    s:string;
  begin
    readln(n);
    readln(s);
    if n mod 2=0 then
     begin
       for i:=1 to n do
        if i mod 2=1 then write(s[i]) else
        if i<>n then write(s[i],'-') else write(s[i]);
     end else
     begin
       if n=3 then write(s) else write(copy(s,1,3)+'-');
       for i:=4 to n do
        if i mod 2=0 then write(s[i]) else
        if i=n then write(s[i]) else write(s[i],'-');
     end;
    writeln;
  end.