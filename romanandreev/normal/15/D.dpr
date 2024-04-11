{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;
const sh=1023;
      inf=maxlongint div 2;
var rm,a,ws:array[0..2*sh+7,0..2*sh+7]of int;
    sum,f:array[0..1010,0..1010]of int64;
    n,m,i,j,x,y,kl,ka,k,l,mn:int;
    aa,a1,a2,a3:array[0..1000000]of int64;
function min2(x,y1,y2:int):int;
begin
  result:=inf;
  y1:=y1+sh;
  y2:=y2+sh;
  while y1<=y2 do begin
    result:=min(result,rm[x][y1]);
    result:=min(result,rm[x][y2]);
    y1:=(y1+1)div 2;
    y2:=(y2-1)div 2;
  end;
end;
function min1(x1,x2,y1,y2:int):int;
begin
  result:=inf;
  x1:=x1+sh;
  x2:=x2+sh;
  while x1<=x2 do begin
    result:=min(result,min2(x1,y1,y2));
    result:=min(result,min2(x2,y1,y2));
    x1:=(x1+1)div 2;
    x2:=(x2-1)div 2;
  end;
end;
procedure sort(l, r: int);
var
  i, j:int;
  x1,x2,x3, y: int64;
begin
  if l>=r then exit;
  i := l; j := r;
  x1 := a1[(l*7+r*13) DIV 20];
  x2 := a2[(l*7+r*13) DIV 20];
  x3 := a3[(l*7+r*13) DIV 20];
  repeat
    while (a3[i] < x3)or((a3[i]=x3)and((a1[i]<x1)or((a1[i]=x1)and(a2[i]<x2)))) do i := i + 1;
    while (a3[j] > x3)or((a3[j]=x3)and((a1[j]>x1)or((a1[j]=x1)and(a2[j]>x2)))) do j := j - 1;
    if i <= j then
    begin
      y := a1[i]; a1[i] := a1[j]; a1[j] := y;
      y := a2[i]; a2[i] := a2[j]; a2[j] := y;
      y := a3[i]; a3[i] := a3[j]; a3[j] := y;
      i := i + 1; j := j - 1;
    end;
  until i > j;
  if l < j then sort(l, j);
  if i < r then sort(i, r);
end;
begin
  //reset(input,'input.txt');
 // rewrite(output,'output.txt');
  readln(n,m,x,y);
  fillchar(a,sizeof(a),0);
  fillchar(sum,sizeof(sum),0);
  fillchar(ws,sizeof(ws),0);
  for i:=1 to n do
    for j:=1 to m do read(a[i][j]);
  for i:=1 to n do
    for j:=1 to m do begin
      sum[i][j]:=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    end;
  for i:=0 to sh*2+5 do
    for j:=0 to sh*2+5 do
      rm[i][j]:=inf;
  for i:=1 to n do
    for j:=1 to m do
      rm[i+sh][j+sh]:=a[i][j];
  for i:=1 to n do
    for j:=sh downto 1 do begin
      rm[i+sh][j]:=min(rm[i+sh][j*2],rm[i+sh][j*2+1]);
    end;
  for i:=sh downto 1 do
    for j:=1 to sh+m do begin
      rm[i][j]:=min(rm[i*2][j],rm[i*2+1][j]);
    end;
  kl:=0;
  for i:=1 to n-x+1 do
    for j:=1 to m-y+1 do begin
      f[i][j]:=sum[i+x-1][j+y-1]-sum[i-1][j+y-1]-sum[i+x-1][j-1]+sum[i-1][j-1]-min1(i,i+x-1,j,j+y-1)*int64(x)*y;
      inc(kl);
      a1[kl]:=i;
      a2[kl]:=j;
      a3[kl]:=f[i][j];
    end;
  sort(1,kl);
  ka:=0;
  for i:=1 to kl do begin
    if (ws[a1[i]][a2[i]]=0)and
       (ws[a1[i]+x-1][a2[i]]=0)and
       (ws[a1[i]][a2[i]+y-1]=0)and
       (ws[a1[i]+x-1][a2[i]+y-1]=0) then begin
        inc(ka);
        aa[ka]:=i;
        for j:=a1[i] to a1[i]+x-1 do
          for k:=a2[i] to a2[i]+y-1 do
            ws[j][k]:=1;
       end;
  end;
  writeln(ka);
  for i:=1 to ka do begin
    writeln(a1[aa[i]],' ',a2[aa[i]],' ',a3[aa[i]]);
  end;
end.