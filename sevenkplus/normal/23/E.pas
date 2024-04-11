{$M 16777216}
const mo=10000;
type big=array[0..50] of longint;
var he,d:array[1..700] of longint;
    ne,ad:array[-700..700] of longint;
    f:array[1..700,0..700] of big;
    tmp:array[1..700] of big;
    xxx:big;
    v:array[1..700] of boolean;
    n,i,x,y:longint;
procedure mul1(x,y,z:longint);//tmp[x]*f[y,z]
  var i,j:longint;
  begin
    fillchar(xxx,sizeof(xxx),0);
    for i:=1 to tmp[x][0] do
      for j:=1 to f[y,z][0] do
        begin
          inc(xxx[i+j-1],tmp[x][i]*f[y,z][j]);
          inc(xxx[i+j],xxx[i+j-1] div mo);
          xxx[i+j-1]:=xxx[i+j-1] mod mo;
        end;
    xxx[0]:=tmp[x][0]+f[y,z][0]+1;
    while (xxx[0]<>0) and (xxx[xxx[0]]=0) do dec(xxx[0]);
  end;
procedure mul2(x,y,z:longint);//f[x,y]*z
  var i,g:longint;
  begin
    g:=0;xxx[0]:=f[x,y][0];
    for i:=1 to f[x,y][0] do
      begin
        xxx[i]:=f[x,y][i]*z+g;
        g:=xxx[i] div mo;
        dec(xxx[i],g*mo);
      end;
    while g<>0 do
      begin
        inc(xxx[0]);xxx[xxx[0]]:=g mod mo;g:=g div mo;
      end;
  end;
function sm1(x,y:longint):boolean;//f[x,y]<xxx
  var i:longint;
  begin
    if f[x,y][0]<xxx[0] then begin sm1:=true;exit;end else
    if f[x,y][0]>xxx[0] then begin sm1:=false;exit;end;
    for i:=xxx[0] downto 1 do
      if f[x,y][i]<xxx[i] then begin sm1:=true;exit;end else
      if f[x,y][i]>xxx[i] then begin sm1:=false;exit;end;
    begin sm1:=false;exit;end;
  end;
function sm2(x:longint):boolean;//f[x,0]<xxx
  var i:longint;
  begin
    if f[x,0][0]<xxx[0] then begin sm2:=true;exit;end else
    if f[x,0][0]>xxx[0] then begin sm2:=false;exit;end;
    for i:=xxx[0] downto 1 do
      if f[x,0][i]<xxx[i] then begin sm2:=true;exit;end else
      if f[x,0][i]>xxx[i] then begin sm2:=false;exit;end;
    begin sm2:=false;exit;end;
  end;
procedure ff(k:longint);
  var p,i,j,xx:longint;
  begin
    v[k]:=true;f[k,1,0]:=1;f[k,1,1]:=1;d[k]:=1;p:=he[k];
    while p<>0 do
      begin
        if not v[ad[p]] then
          begin
            xx:=ad[p];ff(xx);
            for i:=1 to d[k] do tmp[i]:=f[k,i];
            for i:=1 to d[k] do
              for j:=0 to d[xx] do
                begin
                  mul1(i,xx,j);
                  if sm1(k,i+j) then f[k,i+j]:=xxx;
                end;
            inc(d[k],d[xx]);
          end;
        p:=ne[p];
      end;
    for i:=1 to d[k] do
      begin
        mul2(k,i,i);
        if sm2(k) then f[k,0]:=xxx;
      end;
  end;
begin
  readln(n);
  fillchar(he,sizeof(he),0);
  for i:=1 to n-1 do
    begin
      readln(x,y);
      ne[ i]:=he[x];he[x]:= i;ad[ i]:=y;
      ne[-i]:=he[y];he[y]:=-i;ad[-i]:=x;
    end;
  fillchar(f,sizeof(f),0);
  fillchar(v,sizeof(v),false);
  ff(1);
  write(f[1,0,f[1,0,0]]);
  for i:=f[1,0,0]-1 downto 1 do
    write(f[1,0,i] div 1000,f[1,0,i] div 100 mod 10,
          f[1,0,i] div 10 mod 10,f[1,0,i] mod 10);
  writeln;
end.