var s:ansistring;
    a:array['a'..'z']of longint;
    i,k,l,r,n,m:Longint;
    j:char;
  begin
    readln(s);
    read(k);
    n:=0;
    for j:='a' to 'z' do
     begin
       read(a[j]);
       if a[j]>n then n:=a[j];
     end;
    for i:=1 to length(s) do
     m:=m+(a[s[i]]*i);
    for i:=length(s)+1 to length(s)+k do
     m:=m+(n*i);
    writeln(m);
  end.