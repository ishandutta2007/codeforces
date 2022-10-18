var n,m,i,j,k,ans,l,r:longint;
    s:ansistring;
    a,b:array[1..100000]of longint;
  begin
    readln(s);
    s:=s+' ';
    l:=0;
    for i:=1 to length(s)-1 do
     begin
      if copy(s,i,2)='AB' then begin inc(n); a[n]:=i; end;
      if copy(s,i,2)='BA' then begin inc(m); b[m]:=i; end;
     end;
    for i:=1 to n do
     for j:=m downto 1 do
      if (a[i]+1<>b[j]) and (b[j]+1<>a[i])
      then begin writeln('YES'); halt; end;
    writeln('NO');
  end.