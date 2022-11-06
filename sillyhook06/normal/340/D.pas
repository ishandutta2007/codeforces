var
d,a:array[0..100000] of longint;
len,i,k,n:longint;
Function min(t:longint):longint;
var
s,w,mid:longint;
begin
s:=0;w:=len;
while s<w do
begin
mid:=(s+w)div 2;
if d[mid]<=t then s:=mid+1 else w:=mid;
end;
min:=s;
end;
begin
readln(n);
for i:=1 to n do read(a[i]);
readln;
len:=0;
d[0]:=-maxlongint;
for i:=1 to n do begin
if a[i]>=d[len] then begin
inc(len);
d[len]:=a[i];
end else begin
k:=min(a[i]);
d[k]:=a[i];
end;
end;
writeln(len);
end.