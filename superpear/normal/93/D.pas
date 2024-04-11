const bigp=1000000007;

type matrix=array[0..9,0..9] of longint;

var a:matrix;
    l,r,i,c1,l1,r1:longint;
    f:array[0..50] of matrix;

function mpow(a,b:longint):longint;
  var d:longint;
  begin
    if b=0 then exit(1);
    d:=mpow(a,b div 2);
    d:=int64(d)*d mod bigp;
    if b mod 2=1 then d:=int64(d)*a mod bigp;
    exit(d);
  end;

function cheng(a,b:matrix):matrix;
  var c:matrix;
      i,j,k:longint;
  begin
    fillchar(c,sizeof(c),0);
    for i:=1 to 9 do
      for j:=1 to 9 do
        for k:=1 to 9 do
          c[i,j]:=(c[i,j]+int64(a[i,k])*b[k,j]) mod bigp;
    exit(c);
  end;

function getans(s:longint):longint;
  var i,ls,j:longint;
      b,b1:array[0..9] of longint;
  begin
    if s=0 then exit(0);
    if s=1 then exit(4);
    for i:=1 to 8 do b[i]:=1;
    b[9]:=12;
    s:=s-2;
    ls:=0;
    while s>0 do
      begin
        if s mod 2=1 then
          begin
            fillchar(b1,sizeof(b1),0);
            for i:=1 to 9 do
              for j:=1 to 9 do
                b1[j]:=(b1[j]+int64(b[i])*f[ls,i,j]) mod bigp;
            b:=b1;
          end;
        inc(ls);
        s:=s div 2;
      end;
    exit(b[9]);
  end;

begin

  fillchar(a,sizeof(a),0);
  a[1,5]:=1;
  a[2,7]:=1;a[2,8]:=1;
  a[3,6]:=1;
  a[4,7]:=1;a[4,8]:=1;
  a[5,1]:=1;a[5,2]:=1;
  a[6,3]:=1;a[6,4]:=1;
  a[7,1]:=1;a[7,2]:=1;
  a[8,3]:=1;a[8,4]:=1;

  a[1,9]:=1;a[3,9]:=1;
  a[2,9]:=2;a[4,9]:=2;a[5,9]:=2;a[6,9]:=2;a[7,9]:=2;a[8,9]:=2;
  a[9,9]:=1;
  f[0]:=a;
  for i:=1 to 35 do
    f[i]:=cheng(f[i-1],f[i-1]);
  readln(l,r);
  c1:=getans(r)-getans(l-1);
  c1:=(c1+bigp) mod bigp;
  l1:=l;
  r1:=r;
  if l1 mod 2=0 then inc(l1);
  if r1 mod 2=0 then dec(r1);
  if l1<=r1 then
    c1:=(int64(c1)+(getans(r1 div 2+1)-getans(l1 div 2))+bigp) mod bigp;
  c1:=c1*int64(mpow(2,bigp-2)) mod bigp;
  writeln(c1);
end.