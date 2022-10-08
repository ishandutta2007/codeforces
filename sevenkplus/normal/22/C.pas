{$M 16777216}
var v,i,j:longint;
    m,n,max:int64;
function p(a:longint):longint;
  begin
    if a=0 then exit(v);
    if a>=v then exit(a+1);
    exit(a);
  end;
procedure add(i,j:longint);
  begin
    if i>j then writeln(j,' ',i) else writeln(i,' ',j);
  end;
begin
  readln(n,m,v);
  max:=(n-2)*(n-3) div 2+n-1;
  if (m<n-1) or (m>max) then begin writeln(-1);halt;end;
  for i:=1 to n-1 do
    begin
      if m=0 then halt;
      add(v,p(i));dec(m);
    end;
  for i:=1 to n-3 do
    for j:=i+1 to n-2 do
      begin
        if m=0 then halt;
        add(p(i),p(j));dec(m);
      end;
end.