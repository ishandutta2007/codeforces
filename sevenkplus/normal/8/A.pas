program A_;
var i,l,p:longint;
    s,a,b,t:ansistring;
    f,r:boolean;
begin
//  assign(input,'A.in');reset(input);
//  assign(output,'A.out');rewrite(output);
  readln(s);readln(a);readln(b);
  l:=length(s);
  //forward
  f:=true;t:=s;
  p:=pos(a,t);
  if p=0 then f:=false else delete(t,1,p+length(a)-1);
  if pos(b,t)=0 then f:=false;
  //backward
  r:=true;t:=s;
  for i:=1 to l do t[i]:=s[l-i+1];
  p:=pos(a,t);
  if p=0 then r:=false else delete(t,1,p+length(a)-1);
  if pos(b,t)=0 then r:=false;
  if f and r then writeln('both') else
  if f then writeln('forward') else
  if r then writeln('backward') else writeln('fantasy');
//  close(input);close(output);
end.