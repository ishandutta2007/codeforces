program B;
{$inline on}
var p1,s1,p2,s2,t1,t2,a:array[0..100000] of longint;
    n,i,n1,n2,v,p,k,v1,j,m,d,l:longint;
function min(a,b:longint):longint;inline;
  begin
    if a<b then exit(a) else exit(b);
  end;
procedure qs1(l,r:longint);
  var i,j,t,x:longint;
  begin
    i:=l;j:=r;x:=p1[(l+r) shr 1];
    repeat
      while p1[i]>x do inc(i);
      while p1[j]<x do dec(j);
      if i<=j then
        begin
          t:=p1[i];p1[i]:=p1[j];p1[j]:=t;
          t:=s1[i];s1[i]:=s1[j];s1[j]:=t;
          inc(i);dec(j);
        end;
    until i>j;
    if i<r then qs1(i,r);
    if l<j then qs1(l,j);
  end;
procedure qs2(l,r:longint);
  var i,j,t,x:longint;
  begin
    i:=l;j:=r;x:=p2[(l+r) shr 1];
    repeat
      while p2[i]>x do inc(i);
      while p2[j]<x do dec(j);
      if i<=j then
        begin
          t:=p2[i];p2[i]:=p2[j];p2[j]:=t;
          t:=s2[i];s2[i]:=s2[j];s2[j]:=t;
          inc(i);dec(j);
        end;
    until i>j;
    if i<r then qs2(i,r);
    if l<j then qs2(l,j);
  end;
begin
//  assign(input,'B.in');reset(input);
//  assign(output,'B.out');rewrite(output);
  readln(n,k);k:=min(k,n shl 1);n1:=0;n2:=0;
  for i:=1 to n do
    begin
      readln(v,p);
      if v=1 then
        begin
          inc(n1);p1[n1]:=p;s1[n1]:=i;
        end else
        begin
          inc(n2);p2[n2]:=p;s2[n2]:=i;
        end;
    end;
  qs1(1,n1);qs2(1,n2);
  t1[0]:=0;for i:=1 to n1 do t1[i]:=t1[i-1]+p1[i];
  t2[0]:=0;for i:=1 to n2 do t2[i]:=t2[i-1]+p2[i];
  v1:=min(n2,k shr 1);
  m:=-1107351;
  for i:=0 to v1 do
    begin
      j:=min(n1,k-i shl 1);
      if t2[i]+t1[j]>m then
        begin
          m:=t2[i]+t1[j];d:=i;
        end
    end;
  writeln(m);
  j:=min(n1,k-d shl 1);
  for i:=1 to d do writeln(s2[i]);
  for i:=1 to j do writeln(s1[i]);
//  close(input);close(output);
end.