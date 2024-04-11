const bigp=1000000007;

var tt,gb,ls,s,i,j,k:longint;
    st:string;
    f:array[0..2700,0..200] of longint;

begin
  fillchar(f,sizeof(f),0);
  f[0,0]:=1;
  for i:=1 to 2700 do
    for j:=1 to 100 do
      for k:=1 to 26 do
        if i>=k then
          f[i,j]:=(f[i,j]+f[i-k,j-1]) mod bigp;
  readln(tt);
  for gb:=1 to tt do
    begin
      readln(st);
      ls:=length(st);
      s:=0;
      for i:=1 to ls do s:=s+ord(st[i])-96;
      writeln((f[s,ls]-1+bigp) mod bigp);
    end;
end.