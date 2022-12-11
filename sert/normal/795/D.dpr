var a,b:array[1..500000]of longint;
	ua,ub:array[1..500000]of longint;
    n,l,r,f,i:longint;
begin
f := 0;
readln(n,l,r);
for i:=1 to n do read(a[i]);
for i:=1 to n do read(b[i]);
for i:=l to r do inc(ua[a[i]]);
for i:=l to r do inc(ub[b[i]]);
for i:=1 to n do if ua[i] <> ub[i] then f := 1;
for i:=1 to l-1 do if a[i] <> b[i] then f := 1;
for i:=r+1 to n do if a[i] <> b[i] then f:=1;
if f = 1 then write('LIE') else write('TRUTH');
end.