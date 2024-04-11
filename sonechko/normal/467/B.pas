uses math;
var n,m,i,j,k,l,r:longint;
    s,s1:ansistring;
    a:array[1..1000]of longint;
function ziko(n:longint):ansistring;
 var i:longint;
     s:ansistring;
  begin
    s:='';
    while n>0 do
     begin
       if n mod 2=0 then s:='0'+s else s:='1'+s;
       n:=n div 2;
     end;
    ziko:=s;
  end;
function liko(s,t:ansistring):boolean;
 var i,j,r:longint;
  begin
    r:=0;
    while length(t)<>length(s) do
     begin
       if length(s)<length(t) then s:='0'+s else t:='0'+t;
     end;
    for i:=1 to length(t) do
     if s[i]<>t[i] then inc(r);
    if r<=k then liko:=true else liko:=false;
  end;
  begin
    read(n,m,k);
    for i:=1 to m do
     read(a[i]);
    read(l);
    s:=ziko(l);
    for i:=1 to m do
     if liko(ziko(a[i]),s) then inc(r);
    writeln(r);
  end.