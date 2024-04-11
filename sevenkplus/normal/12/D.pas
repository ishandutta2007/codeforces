program D;
var x,y,z,p,a:array[1..500000] of longint;
    i,s,n:longint;
procedure qs1(l,r:longint);
  var i,j,t,x:longint;
  begin
    i:=l;j:=r;x:=p[(l+r)shr 1];
    repeat
      while p[i]<x do inc(i);
      while p[j]>x do dec(j);
      if i<=j then
        begin
          t:=p[i];p[i]:=p[j];p[j]:=t;
          inc(i);dec(j);
        end;
    until i>j;
    if i<r then qs1(i,r);
    if l<j then qs1(l,j);
  end;
function bt(k:longint):longint;
  var l,r,m:longint;
  begin
    l:=1;r:=n;
    while true do
      begin
        m:=(l+r) shr 1;
        if p[m]=k then exit(n-m) else
        if p[m]>k then r:=m-1 else l:=m+1;
      end;
  end;
procedure qs2(l,r:longint);
  var i,j,t,xx,zz:longint;
  begin
    i:=l;j:=r;xx:=x[p[(l+r)shr 1]];zz:=z[p[(l+r)shr 1]];
    repeat
      while(z[p[i]]>zz)or((z[p[i]]=zz)and(x[p[i]]>xx))do inc(i);
      while(z[p[j]]<zz)or((z[p[j]]=zz)and(x[p[j]]<xx))do dec(j);
      if i<=j then
        begin
          t:=p[i];p[i]:=p[j];p[j]:=t;
          inc(i);dec(j);
        end;
    until i>j;
    if i<r then qs2(i,r);
    if l<j then qs2(l,j);
  end;
function max(x:longint):longint;
  var p:longint;
  begin
    p:=0;
    while x>0 do
      begin
        if a[x]>p then p:=a[x];
        dec(x,x and (x xor(x-1)));
      end;
    max:=p;
  end;
procedure add(x,y:longint);
  begin
    while x<=n do
      begin
        if a[x]<y then a[x]:=y;
        inc(x,x and (x xor(x-1)));
      end;
  end;
begin
//  assign(input,'D.in');reset(input);
//  assign(output,'D.out');rewrite(output);
  readln(n);
  for i:=1 to n do begin read(x[i]);p[i]:=x[i];end;
  qs1(1,n);
  for i:=1 to n do x[i]:=bt(x[i]);
  for i:=1 to n do begin read(y[i]);p[i]:=i;end;
  for i:=1 to n do read(z[i]);
  qs2(1,n);
  fillchar(a,sizeof(a),0);s:=0;
  for i:=1 to n do
    begin
      if max(x[p[i]])>y[p[i]] then inc(s);
      add(x[p[i]]+1,y[p[i]]);
    end;
  writeln(s);
//  close(input);close(output);
end.