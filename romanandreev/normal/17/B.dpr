{$APPTYPE CONSOLE}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
//{$D+,I+,L+,Q+,R+,S+,O-,H+}

uses
  SysUtils,Math;
type int=longint;
const inf=maxlongint div 2;
var n,i,j,mn,m,ans,k:int;
    a:array[0..1001,0..1001]of int;
    q,d,b,x,y,c:array[0..100001]of int;
procedure swap(var a,b:int);
var c:int;
begin
  c:=a;
  a:=b;
  b:=c;
end;
begin
 // reset(input,'input.txt');
 // rewrite(output,'output.txt');
  readln(n);
  for i:=1 to n do read(q[i]);
  readln(m);
  for i:=1 to n do
    for j:=1 to n do
      if i<>j then
        a[i][j]:=inf
      else
        a[i][j]:=0;
  for i:=1 to m do begin
    read(x[i],y[i],c[i]);
  end;
  for i:=1 to m do
    for j:=i+1 to m do
      if c[i]>c[j] then begin
        swap(x[i],x[j]);
        swap(y[i],y[j]);
        swap(c[i],c[j]);
      end;
  for i:=1 to n do b[i]:=0;
  for i:=1 to m do begin
    if b[y[i]]=0 then begin
      b[y[i]]:=1;
      ans:=ans+c[i];
    end;
  end;
  k:=0;
  for i:=1 to n do if b[i]=0 then inc(k);
  if k>1 then writeln(-1) else
  writeln(ans);
end.