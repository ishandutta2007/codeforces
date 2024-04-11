program Bulldozer;
var n, i, h, v, ansl: integer;
asfh, asfv, ans: array [1..50] of integer;
begin
readln(n);
for i:=1 to n do
  begin
  asfh[i]:=0;
  asfv[i]:=0;
  end;
ansl:=0;
for i:=1 to n*n do
  begin
  readln(h,v);
  if (asfh[h]=0) and (asfv[v]=0) then
    begin
    ansl:=ansl+1;
    asfh[h]:=1;
    asfv[v]:=1;
    ans[ansl]:=i;
    end;
  end;
write(ans[1]);
for i:=2 to n do write(' ',ans[i]);
end.