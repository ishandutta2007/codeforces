{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;
const inf=maxlongint div 2;
var x0,y0,i,j,k,n,msk2,kl:int;
    x,y,s:array[0..25]of int;
    d,bc1:array[0..1 shl 24]of int;
    f:array[0..100,0..100]of int;
procedure bct(i:int);
var j:int;
begin
  if i=0 then exit;
  bct(bc1[i]);
  for j:=0 to n-1 do if ((i shr j)and 1=1)and((bc1[i] shr j)and 1=0) then
    write(j+1,' ');
  write(0,' ');
end;
begin
  //reset(input,'c.in');
  //rewrite(output,'c.out');
  readln(x0,y0);
  readln(n);
  for i:=0 to n-1 do read(x[i],y[i]);
  for i:=0 to n-1 do begin
    x[i]:=x[i]-x0;
    y[i]:=y[i]-y0;
  end;
  for i:=0 to 1 shl n-1 do begin
    d[i]:=inf;
  end;
  for i:=0 to n-1 do
    for j:=0 to n-1 do
      f[i][j]:=x[i]*x[i]+y[i]*y[i]+
               x[j]*x[j]+y[j]*y[j]+
               (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
  d[0]:=0;
  for i:=1 to 1 shl n-1 do begin
    kl:=0;
    for j:=0 to n-1 do if (i shr j)and 1=1 then begin
      inc(kl);
      s[kl]:=j;
    end;
    for j:=1 to kl do begin
      msk2:=(i xor (1 shl s[j]));
        if d[i]>d[msk2]+f[s[j]][s[j]] then begin
          d[i]:=d[msk2]+f[s[j]][s[j]];
          bc1[i]:=msk2;
        for k:=j+1 to kl do begin
          msk2:=(i xor (1 shl s[j])) xor (1 shl s[k]);
          if d[i]>d[msk2]+f[s[j]][s[k]] then begin
            d[i]:=d[msk2]+f[s[j]][s[k]];
            bc1[i]:=msk2;
          end;
        end;
      end;
    end;
  end;
  writeln(d[1 shl n-1]);
  write(0,' ');
  bct(1 shl n-1);
end.