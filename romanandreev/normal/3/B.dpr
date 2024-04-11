program Zb;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;
type arr=array[0..1000000]of integer;
var n,i,k,ka,x,y,k1,k2,tk:integer;
    ans:int64;
    a,b,aa,nma,nmb:arr;
procedure sort(var a,b:arr;l, r: Integer);
var
  i, j, x, y: integer;
begin
  if l>=r then exit;
  i := l; j := r; x := a[(l*7+r*13) DIV 20];
  repeat
    while a[i] > x do i := i + 1;
    while x > a[j] do j := j - 1;
    if i <= j then
    begin
      y := a[i]; a[i] := a[j]; a[j] := y;
      y := b[i]; b[i] := b[j]; b[j] := y;
      i := i + 1; j := j - 1;
    end;
  until i > j;
  if l < j then sort(a,b, l, j);
  if i < r then sort(a,b, i, r);
end;

begin
  //reset(input,'b.in');
  //rewrite(output,'b.out');
  readln(n,k);
  k1:=0;
  k2:=0;
  for i:=1 to n do begin
    readln(x,y);
    if x=1 then begin
      inc(k1);
      a[k1]:=y;
      nma[k1]:=i;
    end;
    if x=2 then begin
      inc(k2);
      b[k2]:=y;
      nmb[k2]:=i;
    end;
  end;
  k:=min(k,3*100000);
  a[0]:=maxint div 2;
  sort(a,nma,1,k1);
  sort(b,nmb,1,k2);
  ka:=0;
  ans:=0;
  tk:=k;
  for i:=1 to k2 do begin
    if b[i]<=a[tk]+a[tk-1] then break;
    dec(tk,2);
    inc(ka);
    inc(ans,b[i]);
    aa[ka]:=nmb[i];
  end;
  for i:=1 to min(k1,tk) do begin
    inc(ka);
    aa[ka]:=nma[i];
    inc(ans,a[i]);
  end;
  writeln(ans);
  for i:=1 to ka do write(aa[i],' ');
  writeln;
end.