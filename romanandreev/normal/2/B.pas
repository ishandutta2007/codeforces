program Zb;
{$D-,I-,L-,Q-,R-,S-,O+}
{$APPTYPE CONSOLE}
{$MODE DELPHI}
uses
  SysUtils,
  Math;

const inf=10000000;
type int=longint;
var n,i,j,x0,y0,x:int;
    a,b1,b2,b11,b12,b21,b22,bc1,bc2:array[0..1002,0..1002] of int;
    bol0:boolean;
procedure bct1(x,y:int);
begin
  if (x=1)and(y=1) then exit;
  if bc1[x,y]=1 then begin
    bct1(x-1,y);
    write('D');
  end;
  if bc1[x,y]=2 then begin
    bct1(x,y-1);
    write('R');
  end;
end;
procedure bct2(x,y:int);
begin
  if (x=1)and(y=1) then exit;
  if bc2[x,y]=1 then begin
    bct2(x-1,y);
    write('D');
  end;
  if bc2[x,y]=2 then begin
    bct2(x,y-1);
    write('R');
  end;
end;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(n);
  x0:=1;
  y0:=1;
  bol0:=false;
  for i:=1 to n do begin
    for j:=1 to n do begin
      read(x);
      b11[i][j]:=inf;
      b12[i][j]:=inf;
      b21[i][j]:=inf;
      b22[i][j]:=inf;
      if x=0 then begin
        a[i][j]:=0;
        bol0:=true;
        x0:=i;
        y0:=j;
      end else begin
        a[i][j]:=1;
        while x mod 2=0 do begin
          x:=x div 2;
          inc(b1[i][j]);
        end;
        while x mod 5=0 do begin
          x:=x div 5;
          inc(b2[i][j]);
        end;
      end;
    end;
  end;
  b11[1][1]:=b1[1][1];
  b12[1][1]:=b2[1][1];
  b21[1][1]:=b1[1][1];
  b22[1][1]:=b2[1][1];
  for i:=1 to n do begin
    for j:=1 to n do if (i>1)or(j>1) then begin
      if a[i][j]=1 then begin
        if a[i-1][j]=1 then
        if i>1 then begin
          if (b1[i][j]+b11[i-1][j]<b11[i][j])or
             ((b1[i][j]+b11[i-1][j]=b11[i][j])and(b2[i][j]+b12[i-1][j]<b12[i][j])) then begin
            b11[i][j]:=b1[i][j]+b11[i-1][j];
            b12[i][j]:=b2[i][j]+b12[i-1][j];
            bc1[i][j]:=1;
          end;
        end;
        if a[i-1][j]=1 then
        if i>1 then begin
          if (b2[i][j]+b22[i-1][j]<b22[i][j])or
             ((b2[i][j]+b22[i-1][j]=b22[i][j])and(b1[i][j]+b21[i-1][j]<b21[i][j])) then begin
            b21[i][j]:=b1[i][j]+b21[i-1][j];
            b22[i][j]:=b2[i][j]+b22[i-1][j];
            bc2[i][j]:=1;
          end;
        end;
        if a[i][j-1]=1 then
        if j>1 then begin
          if (b1[i][j]+b11[i][j-1]<b11[i][j])or
             ((b1[i][j]+b11[i][j-1]=b11[i][j])and(b2[i][j]+b12[i][j-1]<b12[i][j])) then begin
            b11[i][j]:=b1[i][j]+b11[i][j-1];
            b12[i][j]:=b2[i][j]+b12[i][j-1];
            bc1[i][j]:=2;
          end;
        end;
        if a[i][j-1]=1 then
        if j>1 then begin
          if (b2[i][j]+b22[i][j-1]<b22[i][j])or
             ((b2[i][j]+b22[i][j-1]=b22[i][j])and(b1[i][j]+b21[i][j-1]<b21[i][j])) then begin
            b21[i][j]:=b1[i][j]+b21[i][j-1];
            b22[i][j]:=b2[i][j]+b22[i][j-1];
            bc2[i][j]:=2;
          end;
        end;
      end;
    end;
  end;
  if bol0 then begin
    if min(min(b11[n,n],b12[n,n]),min(b21[n,n],b22[n,n]))>=1 then begin
      writeln(1);
      for i:=1 to x0-1 do write('D');
      for i:=1 to y0-1 do write('R');
      for i:=1 to n-x0 do write('D');
      for i:=1 to n-y0 do write('R');
      halt;
    end;
  end;
  if min(b11[n,n],b12[n,n])=inf then begin
    if min(b21[n,n],b22[n,n])=inf then begin
      halt;
    end;
    writeln(min(b21[n,n],b22[n,n]));
    bct2(n,n);
  end;
  if min(b11[n,n],b12[n,n])<min(b21[n,n],b22[n,n]) then begin
  writeln(min(b11[n,n],b12[n,n]));
  bct1(n,n);
  end else begin
  writeln(min(b21[n,n],b22[n,n]));
  bct2(n,n);
  end;
end.