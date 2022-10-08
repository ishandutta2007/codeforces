{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;
var n,i,x,sum,j,k:int;
    ans:int64;
    d:array[0..1000001]of int;
    s:array[0..100]of int64;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(n);
  for i:=1 to 9 do d[i]:=i;
  for i:=10 to 1000000 do begin
    sum:=0;
    x:=i;
    while x>0 do begin
      sum:=sum+x mod 10;
      x:=x div 10;
    end;
    d[i]:=d[sum];
  end;
  for i:=1 to n do inc(s[d[i]]);
  ans:=0;
  for i:=1 to 9 do
    for j:=1 to 9 do
      for k:=1 to 9 do
        if d[i*j]=k then
          inc(ans,s[i]*s[j]*s[k]);
  for i:=1 to n do begin
    for j:=1 to n do
      if i*j<=n then begin
        dec(ans);
      end else
        break;
  end;
  writeln(ans);
end.