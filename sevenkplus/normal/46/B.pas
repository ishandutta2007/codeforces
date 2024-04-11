const ss:array[1..5] of string=('S','M','L','XL','XXL');
var a:array[1..5] of longint;
    n,i,k,x:longint;
    s:string;
procedure doo(x:longint);
  begin
    dec(a[x]);writeln(ss[x]);
  end;
begin
  readln(a[1],a[2],a[3],a[4],a[5]);
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      if s='S' then x:=1 else
      if s='M' then x:=2 else
      if s='L' then x:=3 else
      if s='XL' then x:=4 else
      if s='XXL' then x:=5;
      if a[x]>0 then doo(x) else
      if (x<5) and (a[x+1]>0) then doo(x+1) else
      if (x>1) and (a[x-1]>0) then doo(x-1) else
      if (x<4) and (a[x+2]>0) then doo(x+2) else
      if (x>2) and (a[x-2]>0) then doo(x-2) else
      if (x<3) and (a[x+3]>0) then doo(x+3) else
      if (x>3) and (a[x-3]>0) then doo(x-3) else
      if (x<2) and (a[x+4]>0) then doo(x+4) else
      if (x>4) and (a[x-4]>0) then doo(x-4);
    end;
end.