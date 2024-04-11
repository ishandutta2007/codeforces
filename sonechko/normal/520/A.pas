var n,m,i,j,k,ans,l,r:longint;
    a:array['a'..'z']of longint;
    b:array['A'..'Z']of longint;
    h:char;
    s:ansistring;
  begin
    readln(n);
    readln(s);
    for i:=1 to n do
     if s[i] in ['a'..'z'] then inc(a[s[i]]) else inc(b[s[i]]);
    for h:='a' to 'z' do
     if (a[h]=0) and (b[chr(ord(h)-32)]=0) then begin writeln('NO'); halt; end;
    writeln('YES');
  end.