const a:array[1..5,1..5] of longint=
((4,3,2,3,4),
(3,2,1,2,3),
(2,1,0,1,2),
(3,2,1,2,3),
(4,3,2,3,4));
var n,m,i,j,k,l,r:longint;
 begin
   for i:=1 to 5 do
    for j:=1 to 5 do
     begin
       read(l);
       if l=1 then WRITELN(a[i,j]);
     end;
 end.