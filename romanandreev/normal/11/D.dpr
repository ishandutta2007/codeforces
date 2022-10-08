{$APPTYPE CONSOLE}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$MAXSTACKSIZE 1000000000}
uses
  SysUtils,Math;
type int=longint;
var n,m,i,j,x,y,kl,bb,kk:int;
    head,next,e:array[0..1000]of int;
    d:array[0..19,0..1 shl 19]of int64;
    mn:array[0..1 shl 19]of int;
    ans:int64;
    a:array[0..100,0..100]of int;
procedure add(x,y:int);
begin
  inc(kl);
  next[kl]:=head[x];
  head[x]:=kl;
  e[kl]:=y;
end;
begin
{  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);    }
  kl:=0;
  readln(n,m);
  for i:=1 to m do begin
    read(x,y);
    a[x][y]:=1;
    a[y][x]:=1;
  end;
{  n:=19;
  for i:=1 to n do
    for j:=1 to n do if i<>j then
      a[i][j]:=1;  }
  for i:=1 to n do
    for j:=1 to n do if a[i][j]=1 then
      add(i,j);
  for i:=1 to n do
    d[i][1 shl (i-1)]:=1;
  for i:=1 to 1 shl n-1 do begin
    mn[i]:=n+1;
    for j:=1 to n do if (i shr (j-1))and 1=1 then
      mn[i]:=min(mn[i],j);
  end;
  for i:=1 to 1 shl n-1 do begin
    for j:=1 to n do if (i shr (j-1))and 1=1 then begin
      if d[j][i]>0 then begin
        bb:=head[j];
        while bb<>0 do begin
          if e[bb]>=mn[i] then
          if (i shr (e[bb]-1))and 1=0 then
          inc(d[e[bb]][i or (1 shl (e[bb]-1))],d[j][i]);
          bb:=next[bb];
        end;
      end;
    end;
  end;
  ans:=0;
  for i:=1 to 1 shl n-1 do begin
    kk:=0;
    for j:=1 to n do if (i shr (j-1))and 1=1 then inc(kk);
    if kk<=2 then continue;
    bb:=head[mn[i]];
    while bb<>0 do begin
      ans:=ans+d[e[bb]][i];
      bb:=next[bb];
    end;
  end;
  writeln(ans div 2);
end.