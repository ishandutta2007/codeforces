var
 j,n,i:longint;
 f,t,c:array[0..3000]of int64;
begin
 readln(n);
 for i:=1 to n do readln(t[i],c[i]);
 for i:=1 to n do inc(t[i]);
 fillchar(f,sizeof(f),63);
 f[0]:=0;
 for i:=1 to n do for j:=n downto 0 do if (j+t[i]>n)and(f[j]+c[i]<f[n]) then
 f[n]:=f[j]+c[i] else if f[j]+c[i]<f[j+t[i]]then f[j+t[i]]:=f[j]+c[i];
 writeln(f[n]);
end.