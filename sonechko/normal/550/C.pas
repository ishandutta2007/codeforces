var s:string;
    i,j,k,ans,l,r,n,m:longint;
  begin
    ans:=-1;
    readln(s);
    s:='00'+s;
    for i:=1 to length(s) do
     for j:=i+1 to length(s) do
      for k:=j+1 to length(s) do
       begin
         val(s[i],l);
         val(s[j],r);
         l:=l*10+r;
         val(s[k],r);
         l:=l*10+r;
         if l mod 8=0 then begin writeln('YES'); writeln(l); halt; end;
       end;
    writeln('NO');
  end.