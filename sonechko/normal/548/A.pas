Var i,j,l,r,n,m:longint;
    s:ansistring;
function get(s:ansistring):boolean;
 var i:longint;
  begin
    for i:=1 to length(s) div 2 do
     if s[i]<>s[length(s)-i+1] then exit(false);
    exit(true);
  end;
  begin
    readln(s);
    readln(n);
    l:=length(s) div n;
    if length(s) mod n<>0 then begin writeln('NO'); halt; end;
    i:=1;
    while i<=length(s) do
     begin
       if get(copy(s,i,l))=false then begin writeln('NO'); halt; end;
       i:=i+l;
     end;
    writeln('YES');
  end.