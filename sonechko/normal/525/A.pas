var s:ansistring;
    i,j,k,ans,l,r,n,m:longint;
    a:array['A'..'Z']of longint;
  begin
    readln(n);
    readln(s);
    for i:=1 to length(s) do
     if s[i] in ['a'..'z'] then inc(a[chr(ord(s[i])-32)]) else
     if a[s[i]]=0 then inc(ans) else dec(a[s[i]]);
    writeln(ans);
  end.