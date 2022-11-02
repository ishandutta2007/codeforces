var n,i,j,maxk:longint;
    x,y,z:array[0..100] of longint;
    max,t,e,x1,y1,z1:extended;

function dis(x,y,z:longint):extended;
  begin
    exit(sqr(x-x1)+sqr(y-y1)+sqr(z-z1));
  end;

begin
  readln(n);
  for i:=1 to n do
    readln(x[i],y[i],z[i]);
  t:=1;
  x1:=0;y1:=0;z1:=0;
  while t>0.000001 do
    begin
      max:=0;
      maxk:=0;
      for j:=1 to n do
        begin
          e:=dis(x[j],y[j],z[j]);
          if e>max then
            begin
              max:=e;
              maxk:=j;
            end;
        end;
      x1:=x1+(x[maxk]-x1)*t;
      y1:=y1+(y[maxk]-y1)*t;
      z1:=z1+(z[maxk]-z1)*t;
      t:=t*0.999;
    end;
  writeln(x1:0:10,' ',y1:0:10,' ',z1:0:10);
end.