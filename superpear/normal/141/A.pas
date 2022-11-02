var s1,s2,s:ansistring;
    ls1,ls2,ls,i,flag:longint;
    a:array['A'..'Z'] of longint;
    ic:char;
begin
  readln(s1);
  readln(s2);
  ls1:=length(s1);
  ls2:=length(s2);
  fillchar(a,sizeof(a),0);
  for i:=1 to ls1 do
    inc(a[s1[i]]);
  for i:=1 to ls2 do
    inc(a[s2[i]]);
  readln(s);
  ls:=length(s);
  for i:=1 to ls do
    dec(a[s[i]]);
  flag:=1;
  for ic:='A' to 'Z' do
    if a[ic]<>0 then flag:=0;
  if flag=0 then writeln('NO') else writeln('YES');
end.