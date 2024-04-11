var
    n,m,x,y,l,r,c,ans:int64;
    a,b:array[1..111111]of int64;
    i,k:longint;
begin
    read(n,m,x,y,k);
    for i:=1 to k do read(a[i],b[i]);
    ans:=0;
    for i:=1 to k do
    begin
        l:=0;
        r:=1000000000;
        while (l<r) do
        begin
            c:=(l+r+1)div 2;
            if (x+a[i]*c<1)or(x+a[i]*c>n)or(y+b[i]*c<1)or(y+b[i]*c>m)then r:=c-1 else l:=c;
        end;
        ans:=ans+l;
        x:=x+a[i]*l;
        y:=y+b[i]*l;
    end;
    writeln(ans);
end.