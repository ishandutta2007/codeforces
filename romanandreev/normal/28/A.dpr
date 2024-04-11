{$APPTYPE CONSOLE}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$MAXSTACKSIZE 1000000000}
uses
  SysUtils,Math;
type int=longint;
var x,y,a,b,l,aa:array[0..100000]of int;
    n,m,i,j:int;
procedure try1();
begin
  fillchar(b,sizeof(b),0);
  fillchar(aa,sizeof(aa),0);
  for i:=1 to n div 2 do begin
    for j:=1 to m do if b[j]=0 then if l[j]=a[i*2-1]+a[i*2] then begin
      b[j]:=1;
      aa[2*i]:=j;
      break;
    end;
  end;
  for i:=1 to n div 2 do if aa[i*2]=0 then exit;
  writeln('YES');
  for i:=1 to n div 2 do write('-1 ',aa[i*2],' ');
  writeln;
  halt;
end;
procedure try2();
begin
  fillchar(b,sizeof(b),0);
  fillchar(aa,sizeof(aa),0);
  for i:=1 to n div 2 do begin
    for j:=1 to m do if b[j]=0 then if l[j]=a[i*2-2]+a[i*2-1] then begin
      b[j]:=1;
      aa[2*i-1]:=j;
      break;
    end;
  end;
  for i:=1 to n div 2 do if aa[i*2-1]=0 then exit;
  writeln('YES');
  for i:=1 to n div 2 do write(aa[i*2-1],' ','-1 ');
  writeln;
  halt;
end;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(n,m);
  for i:=1 to n do read(x[i],y[i]);
  x[n+1]:=x[1];
  y[n+1]:=y[1];
  for i:=1 to n do a[i]:=abs(x[i]-x[i+1])+abs(y[i]-y[i+1]);
  a[0]:=a[n];
  for i:=1 to m do begin
    read(l[i]);
  end;
  try1;
  try2;
  writeln('NO');
end.