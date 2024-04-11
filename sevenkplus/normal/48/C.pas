const eps=1e-8;
var a:array[1..10000] of longint;
    n,i,mi1,mi2,ma1,ma2:longint;
function nex(x,y:longint):longint;
  begin
    nex:=x*(n+1) div y;
  end;
function nex1(x,y:longint):longint;
  begin
    if x*(n+1) mod y=0 then nex1:=x*(n+1) div y-1 else nex1:=x*(n+1) div y;
  end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  mi1:=1;mi2:=1;ma1:=maxlongint;ma2:=1;
  for i:=1 to n do
    begin
      if (a[i]+1)/i<ma1/ma2 then begin ma1:=a[i]+1;ma2:=i;end;
      if (a[i])/i>mi1/mi2 then begin mi1:=a[i];mi2:=i;end;
    end;
  if nex(mi1,mi2)<>nex1(ma1,ma2) then writeln('not unique') else
    begin
      writeln('unique');writeln(nex(mi1,mi2));
    end;
end.