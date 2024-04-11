var n,m,i,j,k,l,r:longint;
    a:array['a'..'z']of longint;
    h:char;
    s:ansistring;
  begin
    readln(s);
    for i:=1 to length(s) do
     inc(a[s[i]]);
    k:=0;
    for h:='a' to 'z' do
     inc(k,a[h] mod 2);
    if (k=0) or (k mod 2=1) then writeln('First') else writeln('Second');
  end.