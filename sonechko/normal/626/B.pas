var n,m,i,j,k,ans,l,r,ll,rr,p:longint;
    dp:array[0..200,0..200,0..200]of 0..1;
    s:string;
procedure rec(l,r,k:longint);
 begin
   if (dp[l,r,k]=1) then exit;
   dp[l,r,k]:=1;
   if (l>0) and (r>0) then rec(l-1,r-1,k+1);
   if (l>0) and (k>0) then rec(l-1,r+1,k-1);
   if (r>0) and (k>0) then rec(l+1,r-1,k-1);
   if (l>1) then rec(l-1,r,k);
   if (r>1) then rec(l,r-1,k);
   if (k>1) then rec(l,r,k-1);
 end;
  begin
    readln(n);
    readln(s);
    for i:=1 to length(s) do
     if s[i]='R' then l:=l+1 else
     if s[i]='G' then r:=r+1 else k:=k+1;
    rec(l,r,k);
    if dp[0,0,1]=1 then write('B');
    if dp[0,1,0]=1 then write('G');
    if dp[1,0,0]=1 then write('R');
    writeln;
  end.