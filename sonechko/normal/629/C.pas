uses math;
var ans,l,r,n,m,p:int64;
    i,j,k:longint;
    dp1,dp2:array[0..2001,-2001..2001]of int64;
    s:ansistring;
  begin
    readln(n,m);
    m:=n-m;
    readln(s);
    for i:=1 to length(s) do
     begin
      if s[i]='(' then l:=l+1 else l:=l-1;
      p:=max(p,l*-1);
     end;
    dp1[0,0]:=1;
    for i:=1 to m do
     for j:=0 to 2000 do
      for k:=0 to 1 do
      begin
        if k=0 then dp1[i,j]:=(dp1[i,j]+dp1[i-1,j-1]) mod 1000000007 else
        dp1[i,j]:=(dp1[i,j]+dp1[i-1,j+1]) mod 1000000007;
      end;
   { for i:=1 to m do
     for j:=0 to 2000 do
      for k:=0 to 1 do
      begin
        if k=0 then dp2[i,j]:=(dp2[i,j]+dp2[i-1,j-1]) mod 1000000007 else
        dp2[i,j]:=(dp2[i,j]+dp2[i-1,j+1]) mod 1000000007;
      end;}
    for i:=0 to m do
     for k:=p to 2000 do
      begin
        r:=dp1[i,k];
        if (l+k<=2000) then ans:=(ans+r*dp1[m-i,l+k]) mod 1000000007;
      end;
    writeln(ans);
  end.