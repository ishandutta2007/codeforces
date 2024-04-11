program B;
var x:array[1..200] of extended;
    i,n,p:longint;
    m,x0,y0,vb,vs:extended;
begin
//  assign(input,'B.in');reset(input);
//  assign(output,'B.out');rewrite(output);
  readln(n,vb,vs);
  for i:=1 to n do read(x[i]);
  readln(x0,y0);
  m:=maxlongint;p:=0;
  for i:=2 to n do
    if (x[i]/vb+sqrt(sqr(x0-x[i])+sqr(y0))/vs)<=m then
      begin
        p:=i;m:=(x[i]/vb+sqrt(sqr(x0-x[i])+sqr(y0))/vs)
      end;
  writeln(p);
//  close(input);close(output);
end.