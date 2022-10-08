program Zc;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;
type mtr=array[1..3,1..3]of integer;
var a0:mtr;
    c:char;
    st,en,i,j:integer;
    q:array[0..1000000]of mtr;
    x:array[0..1000000]of integer;
    s:mtr;
function ended(a:mtr):integer;
var i,j:integer;
begin
  fillchar(s,sizeof(s),0);
  result:=3;
  for i:=1 to 3 do
    for j:=1 to 3 do begin
      s[1][i]:=s[1][i]+a[i][j];
      s[2][j]:=s[2][j]+a[i][j];
      if a[i][j]=0 then result:=0;
    end;
  s[3][1]:=a[1][1]+a[2][2]+a[3][3];
  s[3][2]:=a[3][1]+a[2][2]+a[1][3];
  for i:=1 to 3 do
    for j:=1 to 3 do begin
      if s[i][j]=3 then begin
        result:=1;
        exit;
      end;
      if s[i][j]=-3 then begin
        result:=2;
        exit;
      end;
    end;
end;
procedure add(a:mtr;xd:integer);
var bol:boolean;
    i,j,e:integer;
begin
  bol:=true;
  for i:=1 to 3 do
    for j:=1 to 3 do
      if a[i][j]<>a0[i][j] then bol:=false;
  e:=ended(a);
  if bol then begin
    if e>0 then begin
      if e=3 then writeln('draw');
      if e=1 then writeln('the first player won');
      if e=2 then writeln('the second player won');
    end else begin
      if xd=1 then writeln('first')
              else writeln('second');
    end;
    halt;
  end;
  if e>0 then exit;
  x[en]:=xd;
  inc(en);
end;
begin
//  reset(input,'c.in');
//  rewrite(output,'c.out');
  for i:=1 to 3 do begin
    for j:=1 to 3 do begin
      read(c);
      if c='X' then a0[i][j]:=1;
      if c='0' then a0[i][j]:=-1;
      if c='.' then a0[i][j]:=0;
    end;
    readln;
  end;
  fillchar(q,sizeof(q),0);
  st:=1;
  en:=1;
  add(q[1],1);
  while st<en do begin
    for i:=1 to 3 do
      for j:=1 to 3 do if q[st][i][j]=0 then begin
        q[en]:=q[st];
        q[en][i][j]:=x[st];
        add(q[en],-x[st]);
      end;
    inc(st);
  end;
  writeln('illegal');
end.