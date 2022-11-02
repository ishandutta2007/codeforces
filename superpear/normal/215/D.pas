var gb,m,sum,c1,c2,t1,t2,x,cost,min,left,right,x1,x2:int64;
    tt,i:longint;

function get(e:longint):int64;
  var c,q,u:int64;
  begin
    c:=int64(e)*(t2-t1);
    q:=m-c;
    if q<0 then q:=0;
    u:=int64(q)*x+int64(cost)*e;
    if q>0 then inc(u,cost);
    exit(u);
  end;

begin
  readln(gb,m);
  sum:=0;
  for tt:=1 to gb do
    begin
      readln(t1,t2,x,cost);
      if t1>=t2 then
        sum:=sum+int64(x)*m+cost
      else
        begin
          min:=maxlongint*maxlongint;
          if get(0)<min then min:=get(0);
          if get(m div (t2-t1))<min then min:=get(m div (t2-t1));
          if get((m-1) div (t2-t1)+1)<min then min:=get((m-1) div (t2-t1)+1);
          sum:=sum+min;
        end;
    end;
  writeln(sum);
end.