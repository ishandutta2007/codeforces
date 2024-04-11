program B;
label p;
var s,m:string[10];
    i,j,l:longint;
    c:char;
begin
//  assign(input,'B.in');reset(input);
//  assign(output,'B.out');rewrite(output);
  readln(s);readln(m);
  if s='0' then goto p;
  l:=length(s);
  for i:=1 to l do
    for j:=i+1 to l do
      if s[i]>s[j] then
        begin
          c:=s[i];s[i]:=s[j];s[j]:=c;
        end;
  i:=1;while s[i]='0' do inc(i);
  s:=s[i]+s;delete(s,i+1,1);
  p:if s=m then writeln('OK') else writeln('WRONG_ANSWER');
//  close(input);close(output);
end.