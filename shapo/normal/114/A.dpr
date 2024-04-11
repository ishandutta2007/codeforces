var p,l,k:int64;
    res:longint;
begin
readln(k,l);
p:=k;
res:=0;
while p < l do begin
    inc(res);
    p:=p*k;
   end;
  if p = l then begin
  writeln('YES');
  writeln(res);
  end
  else writeln('NO');
 end.