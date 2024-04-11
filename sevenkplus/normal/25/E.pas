var s1,s2,s3:ansistring;
    p:array[1..301000] of longint;
    s,t:longint;
function r(var s1:ansistring;s2:ansistring):longint;
  var s:ansistring;
      i:longint;
  begin
    s:=s2+'#'+s1;p[1]:=0;
    for i:=2 to length(s) do
      begin
        p[i]:=p[i-1];while (s[p[i]+1]<>s[i]) and (p[i]>0) do p[i]:=p[p[i]];
        if s[p[i]+1]=s[i] then inc(p[i]);
        if p[i]=length(s2) then exit;
      end;
    if p[length(s)]=0 then s1:=s1+s2 else s1:=copy(s1,1,length(s1)-p[length(s)])+s2;
  end;
function q(s1,s2,s3:ansistring):longint;
  begin
    r(s1,s2);r(s1,s3);exit(length(s1));
  end;
begin
  readln(s1);readln(s2);readln(s3);t:=maxlongint;
  s:=q(s1,s2,s3);if s<t then t:=s;
  s:=q(s1,s3,s2);if s<t then t:=s;
  s:=q(s2,s1,s3);if s<t then t:=s;
  s:=q(s2,s3,s1);if s<t then t:=s;
  s:=q(s3,s1,s2);if s<t then t:=s;
  s:=q(s3,s2,s1);if s<t then t:=s;
  writeln(t);
end.