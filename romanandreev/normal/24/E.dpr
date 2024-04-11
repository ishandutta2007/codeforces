{$APPTYPE CONSOLE}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;
var a,v:array[0..1000000]of int;
    n,i,g:int;
    l,r,m:extended;
procedure sort(l,r:int);
var i,j,x,y:int;
begin
  if l>=r then exit;
  i:=l;
  j:=r;
  x:=a[(l*13+r*7) div 20];
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then begin
      y:=a[i];a[i]:=a[j];a[j]:=y;
      y:=v[i];v[i]:=v[j];v[j]:=y;
      inc(i);
      dec(j);
    end;
  until i>j;
  sort(l,j);
  sort(i,r);
end;
function can(t:extended):boolean;
var mx:extended;
    i:int;
begin
  mx:=-1e9-10;
  for i:=1 to n do begin
    if v[i]>0 then begin
      mx:=max(mx,a[i]+v[i]*t);
    end else begin
      if mx>-1e9-5 then 
      if mx>=a[i]+v[i]*t then begin
        result:=true;
        exit;
      end;
    end;
  end;
  result:=false;
end;
begin
 // reset(input,'input.txt');
 // rewrite(output,'output.txt');
  readln(n);
  for i:=1 to n do begin
    read(a[i],v[i]);
  end;
  sort(1,n);
  l:=0;
  r:=1e9+10;
  for g:=1 to 100 do begin
    m:=(l+r)/2;
    if can(m) then r:=m else l:=m;
  end;
  if l>1e9 then writeln(-1)
           else writeln(l:0:15);
end.