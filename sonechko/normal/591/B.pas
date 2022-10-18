var n,m,i,j,k,ans,l,r:longint;
    a:array['a'..'z']of char;
    s:ansistring;
    ch,h1,h2:char;
  begin
    readln(n,m);
    readln(s);
    for ch:='a' to 'z' do
     a[ch]:=ch;
    for i:=1 to m do
     begin
       readln(h1,ch,h2);
       for ch:='a' to 'z' do
        begin
         if a[ch]=h1 then a[ch]:=h2 else
         if a[ch]=h2 then a[ch]:=h1;
        end;
     end;
    for i:=1 to n do
     write(a[s[i]]);
    writeln;
  end.