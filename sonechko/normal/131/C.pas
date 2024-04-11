var n,m,k,ans,l,r:int64;
    i,j:longint;
    a:array[1..30]of longint;
function cnk(n,k:longint):int64;
 var i,l,r:longint;
     ans:int64;
  begin
    for i:=k+1 to n do
     begin
       l:=i;
       r:=2;
       while l>1 do
        if l mod r=0 then begin l:=l div r; inc(a[r]); end else inc(r);
     end;
    for i:=2 to n-k do
     begin
       l:=i;
       r:=2;
       while l>1 do
        if l mod r=0 then begin l:=l div r; dec(a[r]); end else inc(r);
     end;
    ans:=1;
    for i:=2 to 30 do
     while a[i]>0 do
      begin
        ans:=ans*i;
        dec(a[i]);
      end;
    exit(ans);
  end;
  begin
    read(n,m,k);
    ans:=0;
    for i:=4 to n do
     if (k-i>=1) and (k-i<=m) then
      begin
       ans:=ans+cnk(n,i)*cnk(m,k-i);
      end;
    writeln(ans);
  end.