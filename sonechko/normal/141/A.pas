var a,b:array['A'..'Z'] of longint;
    s,t:string;
    i:longint;
    h:char;
  begin
    readln(s);
    for i:=1 to length(s) do
     inc(a[s[i]]);
    readln(s);
    for i:=1 to length(s) do
     inc(a[s[i]]);
    readln(t);
    for i:=1 to length(t) do
     inc(b[t[i]]);
    for h:='A' to 'Z' do
     if a[h]<>b[h] then begin writeln('NO'); halt; end;
   writeln('YES');
  end.