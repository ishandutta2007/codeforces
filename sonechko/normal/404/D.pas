var n,i,j,k:longint;
    s:string;
    dp:array[0..1000000,0..1,0..1]of longint;
  begin
    readln(s);
    if s[1]='*' then dp[1,1,0]:=1;
    if s[1]='0' then dp[1,0,0]:=1;
    if (s[1]='1') and (length(s)>1) then dp[1,0,1]:=1;
    if s[1]='?' then
     begin
       dp[1,1,0]:=1;
       dp[1,0,0]:=1;
       if length(s)>1 then dp[1,0,1]:=1;
     end;
    for i:=2 to length(s) do
     begin
       if (s[i]='?') or (s[i]='0') then
        inc(dp[i,0,0],dp[i-1,0,0]);
       dp[i,0,0]:=dp[i,0,0]mod 1000000007;
       if (s[i]='?') or (s[i]='1') then
        begin
          inc(dp[i,0,1],dp[i-1,0,0]);
          inc(dp[i,0,0],dp[i-1,1,0]);
          dp[i,0,1]:=dp[i,0,1]mod 1000000007;
          dp[i,0,0]:=dp[i,0,0]mod 1000000007;
        end;
       if (s[i]='2') or (s[i]='?') then
        inc(dp[i,0,1],dp[i-1,1,0]);
       dp[i,0,1]:=dp[i,0,1]mod 1000000007;
       if (s[i]='*') or (s[i]='?') then
        inc(dp[i,1,0],dp[i-1,0,1]);
       dp[i,1,0]:=dp[i,1,0]mod 1000000007;
       if (s[i]='*') or (s[i]='?') then
        inc(dp[i,1,0],dp[i-1,1,0]);
       dp[i,1,0]:=dp[i,1,0]mod 1000000007;
     end;
    writeln((dp[length(s),0,0]+dp[length(s),1,0])mod 1000000007);
  end.