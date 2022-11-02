var x1,x2,a,b,c,e,flag:longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin
  readln(x1,x2,a,b);
  if x1>x2 then
    begin
      swap(x1,x2);
      e:=-b;b:=-a;a:=e;
      flag:=-1;
    end
  else
    flag:=1;
  e:=x2-x1;
  if (e>=a) and (e<=b) then
    begin
      writeln('FIRST');
      if flag=1 then writeln(x2) else writeln(x1);
      halt;
    end;
  if a<=0 then
    begin
      writeln('DRAW');
      halt;
    end;
  c:=e mod (a+b);
  if c=0 then
    writeln('SECOND')
  else
    if ((c>0) and (c<a)) or ((c>b) and (c-b<a)) then
      writeln('DRAW')
    else
      begin
        writeln('FIRST');
        if flag=1 then writeln(x1+c) else writeln(x2-c);
      end;
end.