program C;
{$M 16777216}
var s,s1:array[1..100000] of string[32];
    l,a:array[1..100000] of longint;
    n,i:longint;
procedure qs(f,r:longint);
  var i,j,tn,xn:longint;
      x,tx:string[32];
  begin
    i:=f;j:=r;x:=s[(f+r) shr 1];xn:=l[(f+r) shr 1];
    repeat
      while (s[i]<x) or ((s[i]=x) and (l[i]<xn)) do inc(i);
      while (s[j]>x) or ((s[j]=x) and (l[j]>xn)) do dec(j);
      if i<=j then
        begin
          tn:=l[i];l[i]:=l[j];l[j]:=tn;
          tx:=s[i];s[i]:=s[j];s[j]:=tx;
          inc(i);dec(j);
        end;
    until i>j;
    if i<r then qs(i,r);
    if f<j then qs(f,j);
  end;
begin
//  assign(input,'C.in');reset(input);
//  assign(output,'C.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      readln(s[i]);s1[i]:=s[i];l[i]:=i;
    end;
  qs(1,n);
  a[l[1]]:=0;
  for i:=2 to n do
    if s[i]=s[i-1] then a[l[i]]:=a[l[i-1]]+1 else a[l[i]]:=0;
  for i:=1 to n do
    if a[i]=0 then writeln('OK') else writeln(s1[i],a[i]);
//  close(input);close(output);
end.