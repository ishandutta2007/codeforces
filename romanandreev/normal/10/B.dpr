{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;
var w,sum:array[0..100,0..100,0..100]of int;
    n,k,i,j,t,cx,cy,ii,mn,mnx,mny:int;
function per(l1,r1,l2,r2:int):boolean;
begin
  result:=(r1<l2)or(r2<l1);
end;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(n,k);
  fillchar(w,sizeof(w),0);
  cx:=k div 2+1;
  cy:=k div 2+1;
  for i:=1 to k do
    for j:=1 to k do
      for t:=1 to k-i+1 do begin
        sum[i][j][t]:=sum[i-1][j][t]+abs(j-cy)+abs(t+i-1-cx);
      end;
  for i:=1 to k do
    for j:=1 to k do
      for t:=1 to k-i+1 do
        w[i][j][t]:=0;
  for ii:=1 to n do begin
    read(i);
    mn:=-1;
    for j:=1 to k do begin
      for t:=1 to k-i+1 do begin
        if w[i][j][t]=0 then begin
          if (mn=-1)or(sum[i][j][t]<sum[i][mnx][mny]) then begin
            mnx:=j;
            mny:=t;
            mn:=sum[i][j][t];
          end;
        end;
      end;
    end;
    if mn=-1 then writeln(-1) else begin
      for j:=1 to k do
        for t:=1 to k-j+1 do if not per(t,t+j-1,mny,mny+i-1) then
          w[j][mnx][t]:=1;
      writeln(mnx,' ',mny,' ',mny+i-1);
    end;
  end;
end.