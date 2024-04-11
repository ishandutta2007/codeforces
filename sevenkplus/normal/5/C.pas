program C_;
var st,c:array[0..1000000] of longint;
    s:array[1..1000000] of boolean;
    n,i,sn,m,p:longint;
    ch:char;
begin
//  assign(input,'C.in');reset(input);
//  assign(output,'C.out');rewrite(output);
  n:=0;
  while not eoln do
    begin
      inc(n);read(ch);
      s[n]:=ch='(';
    end;
  sn:=0;c[0]:=-1;
  for i:=1 to n do
    if s[i] then
      begin
        c[i]:=-1;inc(sn);st[sn]:=i;
      end else
    if sn=0 then c[i]:=-1 else
      begin
        c[i]:=st[sn];dec(sn);
        while c[c[i]-1]<>-1 do c[i]:=c[c[i]-1];
      end;
  m:=0;p:=1;
  for i:=1 to n do
    if c[i]<>-1 then
      if i-c[i]+1>m then
        begin
          m:=i-c[i]+1;p:=1
        end else
      if i-c[i]+1=m then inc(p);
  writeln(m,' ',p);
//  close(input);close(output);
end.