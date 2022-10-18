var n,m,i,j,k,l,r:longint;
    a,b,c,d:array[1..1000]of string;
    s:ansistring;
  begin
    readln(n);
    for i:=1 to n do
     begin
       readln(s);
       a[i]:=copy(s,1,pos(' ',s)-1);
       b[i]:=copy(s,pos(' ',s)+1,length(s));
     end;
    for i:=1 to n do
     begin
       L:=0;
       for j:=1 to m do
        if a[i]=d[j] then begin d[j]:=b[i]; l:=j; END;
       if l=0 then begin inc(m); c[m]:=a[i]; d[m]:=b[i]; end

     end;
    writeln(m);
    for i:=1 to m do
     writeln(c[i],' ',d[i]);

  end.