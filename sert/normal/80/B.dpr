var j, m, i, k, n, t, q, a, b, r1, r2: longint;
s: string;
begin

read(s);
n:=ord(s[1])-ord('0');
n:=n*10+ord(s[2])-ord('0');
if n >= 12 then n := n - 12;
m:=ord(s[4])-ord('0');
m:=m*10+ord(s[5])-ord('0');
n := n*60+m;
write(n/2:0:3, ' ', m*6);
end.