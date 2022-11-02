var s1,s2:ansistring;
    s:array[0..1000000] of char;
    ls1,ls2,e,i,ans,flag,j:longint;
    a,f:array[0..1000] of longint;
begin
  readln(s1);
  readln(s2);
  ls1:=length(s1);
  ls2:=length(s2);
  for i:=1 to ls1 do s[i]:=s1[i];
  if ls1<ls2 then
    begin
      writeln('0');
      halt;
    end;
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),0);
  for i:=1 to ls2 do
    inc(a[ord(s2[i])-96]);
  for i:=1 to ls2 do
    if s1[i]<>'?' then inc(f[ord(s1[i])-96]) else inc(f[0]);
  ans:=0;
  for i:=1 to ls1-ls2+1 do
    begin
      flag:=1;
      for j:=1 to 26 do
        if f[j]>a[j] then
          begin
            flag:=0;
            break;
          end;
      e:=0;
      for j:=1 to 26 do
        e:=e+a[j]-f[j];
      if (flag=1) and (e<=f[0]) then inc(ans);
      if i=ls1-ls2+1 then break;
      if s[i]<>'?' then dec(f[ord(s[i])-96]) else dec(f[0]);
      if s[i+ls2]<>'?' then inc(f[ord(s[i+ls2])-96]) else inc(f[0]);
    end;
  writeln(ans);
end.