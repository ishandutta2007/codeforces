{$APPTYPE CONSOLE}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$MAXSTACKSIZE 1000000000}
uses
  SysUtils,Math;
type int=longint;
var n,m,i,j,k,t,ml:int;
    d:array[0..100,0..100,0..100]of extended;
    a:array[0..100]of int;
    c:array[0..100,0..100]of int64;
    ans:extended;
function pow(x:extended;n:int):extended;
begin
  if n=0 then begin
    result:=1;
    exit;
  end;
  result:=pow(x,n div 2);
  result:=result*result;
  if n mod 2=1 then
    result:=result*x;
end;
begin
//  reset(input,'input.txt');
//  rewrite(output,'output.txt');
  readln(n,m);
  for i:=1 to m do read(a[i]);
  //d[x,y,z] x rooms y people z maxlen
  d[0,0,0]:=1;
  c[0,0]:=1;
  for i:=1 to n do begin
    c[i,0]:=1;
    for j:=1 to i do
      c[i][j]:=c[i-1][j-1]+c[i-1][j];
  end;
  for i:=1 to m do
    for j:=0 to n do
      for t:=0 to n-j do
        for k:=0 to n do begin
          ml:=max(k,(t-1) div a[i]+1);
          d[i][j+t][ml]:=d[i][j+t][ml]+d[i-1][j][k]*c[n-j,t]*pow(1/(m-i+1),t)*pow((m-i)/(m-i+1),n-j-t);
        end;
  ans:=0;
  for i:=0 to n do
    ans:=ans+d[m][n][i]*i;
  writeln(ans:0:15);
end.