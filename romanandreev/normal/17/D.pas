{$APPTYPE CONSOLE}
{$MODE DELPHI}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
//{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$M 1000000000}
uses
  SysUtils,Math;
type int=longint;
     long=array[0..1000000]of int;
procedure swap(var a,b:int);
var c:int;
begin
  c:=a;
  a:=b;
  b:=c;
end;
procedure readlong(var a:long);
var c:char;
    i:int;
begin
  a[0]:=0;
  while true do begin
    read(c);
    if c=' ' then break;
    inc(a[0]);
    a[a[0]]:=ord(c)-ord('0');
  end;
  for i:=1 to a[0] div 2 do
    swap(a[i],a[a[0]-i+1]);
end;
var b,a:long;
    tk,c:int64;
    i:int;
function minus1(var a:long):long;
var i:int;
begin
  result:=a;
  for i:=1 to a[0] do begin
    result[i]:=a[i]-1;
    if result[i]=-1 then begin
      result[i]:=9;
    end else break;
  end;
  if result[result[0]]=0 then dec(result[0]);
end;
function pow(var tk:int64;a:int):int64;
begin
  if a=0 then begin
    result:=1;
    exit;
  end;
  result:=pow(tk,a div 2);
  result:=(result*result)mod c;
  if a mod 2=1 then
    result:=(result*tk)mod c;
end;
var ff,g,g0:int64;
    j:int;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readlong(b);
  readlong(a);
  read(c);
  if c=1 then begin
    writeln(0);
    halt;
  end;
  tk:=0;
  for i:=b[0] downto 1 do begin
    tk:=(tk*10+b[i])mod c;
  end;
  ff:=(tk+c-1)mod c;
  a:=minus1(a);
  g:=tk;
  tk:=1;
  for i:=1 to a[0] do begin
    tk:=(tk*pow(g,a[i]))mod c;
    g:=pow(g,10);
  end;
  tk:=(tk*ff)mod c;
  if tk=0 then tk:=c;
  writeln(tk);
end.