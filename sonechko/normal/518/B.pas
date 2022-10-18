uses math;
var s,t:ansistring;
    i,j,k,ans,l,r,n,m,p:longint;
    a,c:array['a'..'z']of longint;
    b,d:array['A'..'Z']of longint;
    h,g:char;
  begin
    readln(s);
    n:=length(s);
    readln(t);
    m:=length(t);
    for i:=1 to n do
     if s[i] in ['A'..'Z'] then inc(b[s[i]]) else inc(a[s[i]]);
    for i:=1 to m do
     if t[i] in ['A'..'Z'] then inc(d[t[i]]) else inc(c[t[i]]);
    for h:='a' to 'z' do
     begin
       l:=l+min(a[h],c[h]);
       k:=min(c[h],a[h]);
       a[h]:=a[h]-k;
       c[h]:=c[h]-k;
     end;
    for h:='A' to 'Z' do
     begin
       l:=l+min(b[h],d[h]);
       k:=min(d[h],b[h]);
       d[h]:=d[h]-k;
       b[h]:=b[h]-k;
     end;
    for g:='A' to 'Z' do
     begin
       h:=chr(ord(g)+32);
       p:=a[h]+b[g];
       k:=c[h]+d[g];
       r:=r+min(p,k);
     end;
    writeln(l,' ',r);
  end.