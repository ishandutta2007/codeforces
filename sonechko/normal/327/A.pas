var n,m,i,j,k,l,r,ans:longint;
    a,b:array[0..100]of longint;
  begin
    read(n);
    ans:=0;
    for i:=1 to n do
     read(a[i]);
    l:=1;
    r:=1;
    b[1]:=a[1];
    for i:=2 to n do
     b[i]:=b[i-1]+a[i];
    for i:=1 to n do
     begin
       for j:=i to n do  begin
 
        if (  ((j-i+1)-(b[j]-b[i-1]))  +  (b[i-1])  +  (b[n]-b[j])  >ans) then
         ans:=((j-i+1)-(b[j]-b[i-1]))+(b[i-1])+(b[n]-b[j]);           end;
 
     end;
    writeln(ans);
  end.