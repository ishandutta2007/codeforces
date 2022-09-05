program ads;
var a,b,c:array[-20..200,-20..200] of integer;
i,j,k,l,n1,n2,k1,k2:integer;
begin
read(n1,n2,k1,k2);
for i:=-20 to 200 do
for j:=-20 to 200 do
begin
a[i][j]:=0;
b[i][j]:=0;
c[i][j]:=0;
end;
a[0][0]:=1;
b[k1][0]:=1;
c[0][k2]:=1;
for i:=0 to n1 do
for j:=0 to n2 do
begin
if (i<>0) or (j<>0) then
a[i][j]:=(a[i-1][j]-b[i-1][j]+a[i][j-1]-c[i][j-1]) mod 100000000;
if a[i][j]<0 then inc(a[i][j],100000000);
if (i<>k1) or (j<>0) then
b[i][j]:=(a[i-k1,j-1]-c[i-k1,j-1])mod 100000000;
if b[i][j]<0 then inc(b[i][j],100000000);
if (j<>k2) or (i<>0) then
c[i][j]:=(a[i-1,j-k2]-b[i-1][j-k2]) mod 100000000;
if c[i][j]<0 then inc(c[i][j],100000000);
end;
write(a[n1][n2]);
end.