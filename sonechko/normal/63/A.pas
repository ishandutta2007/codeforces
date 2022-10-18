var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..100]of string;
  begin
    readln(n);
    for i:=1 to n do
     begin
       readln(a[i]);
       b[i]:=copy(a[i],pos(' ',a[i])+1,length(a[i]));
       delete(a[i],pos(' ',a[i]),length(a[i]));
     end;
    for i:=1 to n do
     if b[i]='rat' then writeln(a[i]);
    for i:=1 to n do
     if (b[i]='child') or (b[i]='woman') then writeln(a[i]);
    for i:=1 to n do
     if b[i]='man' then writeln(a[i]);
    for i:=1 to n do
     if b[i]='captain' then writeln(a[i]);
  end.