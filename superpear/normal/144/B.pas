var x1,y1,x2,y2,o,i,j,n,ans,flag:longint;
    x,y,a,b,r:array[0..10000] of longint;

function dis(x1,y1,x2,y2:longint):longint;
  begin
    exit(sqr(x1-x2)+sqr(y1-y2));
  end;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin
  readln(x1,y1,x2,y2);
  if x1>x2 then swap(x1,x2);
  if y1>y2 then swap(y1,y2);
  o:=0;
  for i:=x1 to x2 do
    for j:=y1 to y2 do
      if (i=x1) or (i=x2) or (j=y1) or (j=y2) then
        begin
          inc(o);
          x[o]:=i;y[o]:=j;
        end;
  readln(n);
  for i:=1 to n do
    readln(a[i],b[i],r[i]);
  ans:=0;
  for i:=1 to o do
    begin
      flag:=1;
      for j:=1 to n do
        if dis(x[i],y[i],a[j],b[j])<=r[j]*r[j] then
          begin
            flag:=0;
            break;
          end;
      if flag=1 then inc(ans);
    end;
  writeln(ans);
end.