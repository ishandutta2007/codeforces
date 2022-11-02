var n,i:longint;
    data,left,right,sum:array[0..200000] of int64;
    ans,cs,max:int64;
    
function leven(s:longint):longint;
  begin
    if s mod 2=0 then exit(s) else exit(s-1);
  end;
  
function lodd(s:longint):longint;
  begin
    if s mod 2=1 then exit(s) else exit(s-1);
  end;
  
begin
  readln(n);
  for i:=1 to n-1 do
    read(data[i]);
  left[1]:=0;
  for i:=2 to n do
    if data[i-1]<=1 then left[i]:=0 else
      left[i]:=left[i-1]+leven(data[i-1]);
  right[n]:=0;
  for i:=n-1 downto 1 do
    if data[i]<=1 then right[i]:=0 else
      right[i]:=right[i+1]+leven(data[i]);
  max:=-maxlongint;
  sum[1]:=0;
  for i:=2 to n do
    sum[i]:=sum[i-1]+lodd(data[i-1]);
  ans:=0;
  for i:=1 to n do
    begin
      if left[i]-sum[i]>max then max:=left[i]-sum[i];
      cs:=max+right[i]+sum[i];
      if cs>ans then ans:=cs;
    end;
  writeln(ans);
end.