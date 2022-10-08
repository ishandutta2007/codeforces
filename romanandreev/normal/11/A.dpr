{$APPTYPE CONSOLE}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
//{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$MAXSTACKSIZE 1000000000}
uses
  SysUtils,Math;
type int=longint;
var n,i:int;
    d:int64;
    ans,l,r,m:int64;
    a:array[0..100000]of int64;
begin
  //assign(input,'input.txt');
  //reset(input);
  //assign(output,'output.txt');
  //rewrite(output);
  readln(n,d);
  for i:=1 to n do read(a[i]);
  ans:=0;
  a[0]:=-1000000000;
  for i:=1 to n do begin
    l:=0;
    r:=1000000000;
    while l<r do begin
      m:=(l+r) div 2;
      if a[i]+m*d>a[i-1] then r:=m else l:=m+1;
    end;
    a[i]:=a[i]+l*d;
    ans:=ans+l;
  end;
  writeln(ans);
  //close(input);
  //close(output);
end.