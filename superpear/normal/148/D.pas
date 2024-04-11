var m,n,i,j,k:longint;
    f:array[0..1000,0..1000,0..1] of extended;

function search(n,m,k:longint):extended;
  var e,t:extended;
  begin
    if f[n,m,k]<>-1 then exit(f[n,m,k]);
    if k=0 then
      begin
        if (n<>0) and (m=0) then exit(1);
        if n=0 then exit(0);
        f[n,m,k]:=n/(n+m)+m/(n+m)*search(n,m-1,1);
      end
    else
      begin
        if (n=0) or (m=0) then exit(0);
        e:=m/(n+m);
        t:=n/(n+m-1)*search(n-1,m-1,0);
        if m>1 then t:=t+(m-1)/(n+m-1)*search(n,m-2,0);
        f[n,m,k]:=t*e;
      end;
    exit(f[n,m,k]);
  end;

begin
  readln(n,m);
  for i:=0 to 1000 do
    for j:=0 to 1000 do
      for k:=0 to 1 do
        f[i,j,k]:=-1;
  writeln(search(n,m,0):0:10);
end.