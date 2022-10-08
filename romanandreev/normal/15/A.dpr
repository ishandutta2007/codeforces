{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
//{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;

var n,t,i,j,ans:int;
    x,a:array[0..10000]of int;
procedure swap(var a,b:int);
var c:int;
begin
  c:=a;
  a:=b;
  b:=c;
end;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(n,t);
  t:=t*2;
  for i:=1 to n do begin
    read(x[i],a[i]);
    x[i]:=x[i]*2;
  end;
  for i:=1 to n do
    for j:=i+1 to n do
      if x[i]>x[j] then begin
        swap(x[i],x[j]);
        swap(a[i],a[j]);
      end;
  ans:=2;
  for i:=1 to n-1 do begin
    if x[i+1]-a[i+1]-(x[i]+a[i])<t then;
    if x[i+1]-a[i+1]-(x[i]+a[i])=t then inc(ans);
    if x[i+1]-a[i+1]-(x[i]+a[i])>t then inc(ans,2);
  end;
  writeln(ans);
end.