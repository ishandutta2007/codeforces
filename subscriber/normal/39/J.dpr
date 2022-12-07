{$r-,i-,q-,s-,o+}
type qword = longword;
const
  maxn = 2000000;
var
  rr,p29,pha,sha:array[0..maxn] of qword;
  r,i,j,k,n:longint;
  newh,nha:qword;
  s1,s2:ansistring;
begin
  readln(s1);
  readln(s2);
  p29[0]:=1;
  for i:=1 to length(s2) do nha:=nha*29+(ord(s2[i])-96);
  for i:=1 to length(s1) do
  begin
    pha[i]:=pha[i-1]*29+(ord(s1[i])-96);
    p29[i]:=p29[i-1]*29;
  end;
  sha[length(s1)]:=ord(s1[length(s1)])-96;
  for i:=length(s1)-1 downto 1 do sha[i]:=sha[i+1]+p29[length(s1)-i]*(ord(s1[i])-96);
  for i:=1 to length(s1) do
  begin
    newh:=pha[i-1]*p29[length(s1)-i]+sha[i+1];
    if newh = nha then
    begin
      inc(r);
      rr[r]:=i;
    end;
  end;
  writeln(r);
  for i:=1 to r-1 do write(rr[i], ' ');
  if r>0 then writeln(rr[r]);
end.