var n,m,i,j,k,l,r:longint;
    a,b,c,d:array[1..3000]of string;
    s:ansistring;
  begin
    readln(m,n);
    for i:=1 to n do
     begin
       readln(s);
       a[i]:=copy(s,1,pos(' ',s)-1);
       b[i]:=copy(s,pos(' ',s)+1,length(s));
       if length(b[i])<length(a[i]) then b[i]:=b[i] else b[i]:=a[i];
     end;
    readln(s);
    s:=s+' ';
    m:=0;
    while s<>'' do
     begin
       inc(m);
       c[m]:=copy(s,1,pos(' ',s)-1);
       delete(s,1,pos(' ',s));
     end;
    for i:=1 to m do
     begin
       for j:=1 to n do
        if c[i]=a[j] then write(b[j],' ');
     end;
    writeln;
  end.