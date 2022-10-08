program C_;
var p:array[0..8] of int64;
    f:array[1..1000000] of boolean;
    l:array[0..78498] of longint;
    a,b,c,n,i,j,k,s1:longint;
    s:int64;
begin
//  assign(input,'C.in');reset(input);
//  assign(output,'C.out');rewrite(output);
  readln(n);
  fillchar(p,sizeof(p),0);
  for i:=1 to n do inc(p[i mod 9]);s:=0;
  for a:=0 to 8 do
    for b:=0 to 8 do inc(s,p[a]*p[b]*p[a*b mod 9]);
  fillchar(f,sizeof(f),true);f[1]:=false;
  for i:=2 to 1000 do
    if f[i] then
      begin
        k:=i*i;
        for j:=i to 1000000 div i do
          begin
            f[k]:=false;inc(k,i);
          end;
      end;
  l[0]:=0;
  for i:=2 to 1000000 do
    if f[i] then
      begin
        inc(l[0]);l[l[0]]:=i;
      end;
  for c:=1 to n do
    begin
      i:=1;k:=c;s1:=1;
      while (k<>1) and (not f[k]) do
        begin
          while k mod l[i]<>0 do inc(i);j:=1;
          while k mod l[i]=0 do
            begin
              k:=k div l[i];inc(j);
            end;
          s1:=s1*j;
        end;
      if f[k] then s1:=s1 shl 1;
      dec(s,s1);
    end;
  writeln(s);
//  close(input);close(output);
end.