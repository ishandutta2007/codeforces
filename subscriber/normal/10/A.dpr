var
 j,ans,i,t1,t2,p1,p2,p3,n:longint;
 x,y,f,q:array[0..2000]of longint;

begin
 readln(n,p1,p2,p3,t1,t2);
 for i:=1 to n do read(x[i],y[i]);
 for i:=1 to n do for j:=x[i] to y[i]-1 do q[j]:=1;
 for i:=1 to 1500 do if q[i]=1 then f[i]:=0 else f[i]:=f[i-1]+1;
 ans:=0;
 for i:=x[1] to y[n]-1 do if f[i]<=t1 then inc(ans,p1)else if f[i]<=t1+t2 then inc(ans,p2)else
 inc(ans,p3);
 writeln(ans);
end.