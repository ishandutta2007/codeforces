var n,m,i,j,k,ans,l,r:longint;
    a:array['a'..'z']of longint;
    s,t:ansistring;
    h:char;
  begin
    readln(l);
    readln(s);
    n:=length(s);
    for i:=1 to n do
     inc(a[s[i]]);
    for h:='a' to 'z' do
     if a[h] mod l<>0 then begin writeln('-1'); halt; end else
      begin
        for i:=1 to a[h] div l do
         t:=t+h;
      end;
    s:='';
    for i:=1 to l do
     s:=s+t;
    writeln(s);
  end.