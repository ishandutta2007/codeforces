var s:ansistring;
    i,j,k,ans,l,r,n:longint;
    a:array[0..100000]of longint;
  begin
    readln(s);
    for i:=1 to length(s)-1 do
     if s[i]=s[i+1] then a[i]:=a[i-1]+1 else a[i]:=a[i-1];
    readln(n);
    for i:=1 to n do
     begin
       readln(l,r);
       dec(r);
       writeln(a[r]-a[l-1]);
     end;
  end.