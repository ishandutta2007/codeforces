{$APPTYPE CONSOLE}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$MAXSTACKSIZE 1000000000}
uses
  SysUtils,Math;
type int=longint;
var n,i,j,cn:int;
    p,d,b:array[0..1000]of int;
procedure dfs(v:int);
var i:int;
begin
  if (v<0)or(v>n) then exit;
  if b[v]<>0 then exit;
  b[v]:=cn;
  for i:=1 to n do if abs(i-v)=d[i] then begin
    dfs(i);
  end;
  dfs(v+d[v]);
  dfs(v-d[v]);
end;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(n);
  for i:=1 to n do read(p[i]);
  for i:=1 to n do read(d[i]);
  cn:=0;
  for i:=1 to n do if b[i]=0 then begin
    inc(cn);
    dfs(i);
  end;
//  for i:=1 to n do write(b[i],' ');
  for i:=1 to n do if b[i]<>b[p[i]] then begin
    writeln('NO');
    halt;
  end;
  writeln('YES');
end.