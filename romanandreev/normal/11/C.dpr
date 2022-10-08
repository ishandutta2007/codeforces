{$APPTYPE CONSOLE}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$MAXSTACKSIZE 1000000000}
uses
  SysUtils,Math;
type int=longint;
const vx:array[1..8]of int=(1,1,1,0,0,-1,-1,-1);
const vy:array[1..8]of int=(1,0,-1,-1,1,-1,0,1);
var tt,ti,n,m,i,j,r,ans,k,kl:int;
    a:array[-1000..1000,-1000..1000]of int;
    c:char;
    bol:boolean;
procedure dfs(x,y:int);
var i:int;
begin
  if a[x][y]<>1 then exit;
  a[x][y]:=2;
  inc(kl);
  for i:=1 to 8 do
    dfs(x+vx[i],y+vy[i]);
end;
begin
  readln(tt);
  for ti:=1 to tt do begin
    readln(n,m);
    for i:=-(n+m)*2 to (n+m)*2 do
      for j:=-(n+m)*2 to (n+m)*2 do
        a[i][j]:=0;
    for i:=1 to n do begin
      for j:=1 to m do begin
        read(c);
        if c='1' then a[i][j]:=1;
      end;
      readln;
    end;
   ans:=0;
    for i:=1 to n do
      for j:=1 to m do if a[i][j]=1 then begin
        kl:=0;
        dfs(i,j);
        r:=kl div 4+1;
        if kl mod 4<>0 then continue;
        if r<2 then continue;
        if r>min(n,m) then continue;
        bol:=true;
        for k:=1 to r do begin
          if a[i+k-1][j]=0 then begin bol:=false; break; end;
          if a[i][j+k-1]=0 then begin bol:=false; break; end;
          if a[i+k-1][j+r-1]=0 then begin bol:=false; break; end;
          if a[i+r-1][j+k-1]=0 then begin bol:=false; break; end;
        end;
        if bol then inc(ans);
        bol:=true;
        for k:=1 to r do begin
          if a[i+k-1][j+k-1]=0 then begin bol:=false; break; end;
          if a[i+k-1][j-k+1]=0 then begin bol:=false; break; end;
          if a[i+r*2-2-(k-1)][j+k-1]=0 then begin bol:=false; break; end;
          if a[i+r*2-2-(k-1)][j-k+1]=0 then begin bol:=false; break; end;
        end;
        if bol then inc(ans);
      end;
    writeln(ans);
  end;
end.