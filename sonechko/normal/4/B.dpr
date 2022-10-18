var sum,s,ss,n,m,i,j,k:longint;
    l,r:array[1..100]of longint;
  begin
    read(n,sum);
    s:=0;
    ss:=0;
    for i:=1 to n do
     begin
       read(l[i],r[i]);
       inc(s,l[i]);
       inc(ss,r[i]);
     end;
    if (s>sum) or (ss<sum) then begin writeln('NO'); halt; end;
    writeln('YES');
    s:=sum-s;
    for i:=1 to n do
     begin
      if r[i]-l[i]>s then begin l[i]:=l[i]+s; s:=0; break; end;
      s:=s-(r[i]-l[i]);
      l[i]:=r[i];
     end;
    for i:=1 to n do
     write(l[i],' ');
    writeln;
  end.