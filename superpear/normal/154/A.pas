var st:ansistring;
    k,i,ls,j,ans:longint;
    ch1,ch2:char;
    s:array[0..200000] of char;
    a:array[0..30,0..30] of longint;
    f:array[0..200000,0..30] of longint;

begin
  readln(st);
  ls:=length(st);
  for i:=1 to ls do s[i]:=st[i];
  readln(k);
  fillchar(a,sizeof(a),0);
  for i:=1 to k do
    begin
      read(ch1);read(ch2);
      readln;
      a[ord(ch1)-96,ord(ch2)-96]:=1;
      a[ord(ch2)-96,ord(ch1)-96]:=1;
    end;
  filldword(f,sizeof(f) div 4,maxlongint);
  f[0,0]:=0;
  for i:=0 to ls-1 do
    for j:=0 to 26 do
      if f[i,j]<>maxlongint then
        begin
          if a[j,ord(s[i+1])-96]=0 then
            begin
              if f[i,j]<f[i+1,ord(s[i+1])-96] then
                f[i+1,ord(s[i+1])-96]:=f[i,j];
            end;
          if f[i,j]+1<f[i+1,j] then f[i+1,j]:=f[i,j]+1;
        end;
  ans:=maxlongint;
  for i:=0 to 26 do
    if f[ls,i]<ans then ans:=f[ls,i];
  writeln(ans);
end.