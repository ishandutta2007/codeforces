program Zd;

{$APPTYPE CONSOLE}

uses
  SysUtils;
{$D-,I-,L-,Q-,R-,S-,O+}
type int=longint;
var n,m,i,j,mxi,mxj:int;
    a,b:array[0..10000]of int;
    nx,dp,bc:array[0..501,0..501]of int;
procedure bct(x,y:int);
begin
  if dp[x][y]=0 then exit;
  if bc[x][y]=-1 then begin
    bct(x-1,y);
    exit;
  end;
  bct(x,bc[x][y]);
  write(a[x],' ');
end;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(n);
  for i:=1 to n do read(a[i]);
  readln(m);
  for i:=1 to m do read(b[i]);
  a[0]:=-1;
  b[0]:=-1;
  for i:=1 to n do
    for j:=m downto 1 do begin
      if a[i]=b[j] then nx[i][j]:=j else nx[i][j]:=nx[i][j+1];
    end;
  for i:=0 to n do
    for j:=0 to m do
      dp[i][j]:=-1;
  dp[0][0]:=0;
  for i:=0 to n do
    for j:=0 to m do
    if dp[i][j]<>-1 then begin
      if dp[i+1][j]<dp[i][j] then begin
        dp[i+1][j]:=dp[i][j];
        bc[i+1][j]:=-1;
      end; 
      if a[i]>b[j] then
      if nx[i][j+1]<>0 then begin
        if dp[i][nx[i][j+1]]<dp[i][j]+1 then begin
          dp[i][nx[i][j+1]]:=dp[i][j]+1;
          bc[i][nx[i][j+1]]:=j;
        end;
      end;
    end;
  mxi:=0;
  mxj:=0;
  for i:=0 to n do
    for j:=0 to m do
    if dp[i][j]>dp[mxi,mxj] then begin
      mxi:=i;
      mxj:=j;
    end;
  writeln(dp[mxi,mxj]);
  bct(mxi,mxj);
end.