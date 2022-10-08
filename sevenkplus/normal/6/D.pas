program D;
var h,p,p1:array[1..10] of longint;
    n,a,b,i,m,j:longint;
function max(a,b:longint):longint;
  begin
    if a>b then exit(a) else exit(b);
  end;
procedure fi(k,d,q,r:longint);
  var i:longint;
  begin
    if d>=m then exit;
    if k=n then
      begin
        m:=d;for i:=2 to n-1 do p1[i]:=p[i];exit;
      end;
    if k=n-1 then
      begin
        if q<0 then p[k]:=max(h[n] div b+1,r div a+1) else
          p[k]:=max(max(q div b+1,h[n] div b+1),r div a+1);
        fi(n,d+p[k],0,0);p[k]:=0;
      end else
    if q<0 then
      if r<0 then
      for i:=0 to 6 do
        begin
          p[k]:=i;fi(k+1,d+i,r-i*a,h[k+1]-i*b);p[k]:=0;
        end else
      for i:=0 to r div a+1+6 do
        begin
          p[k]:=i;fi(k+1,d+i,r-i*a,h[k+1]-i*b);p[k]:=0;
        end else
      for i:=q div b+1 to max(q div b+1,r div a+1)+6 do
        begin
          p[k]:=i;fi(k+1,d+i,r-i*a,h[k+1]-i*b);p[k]:=0;
        end;
  end;
begin
//  assign(input,'D.in');reset(input);
//  assign(output,'D.out');rewrite(output);
  readln(n,a,b);
  for i:=1 to n do read(h[i]);
  m:=maxlongint;fi(2,0,h[1],h[2]);writeln(m);
  for i:=2 to n-2 do
    for j:=1 to p1[i] do write(i,' ');
  for i:=1 to p1[n-1]-1 do write(n-1,' ');writeln(n-1);
//  close(input);close(output);
end.