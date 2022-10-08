program C;
var a,b:array[1..100] of longint;
    s:array[1..100] of string;
    n,i,m,j,t,k,p:longint;
    s1:string;
begin
//  assign(input,'C.in');reset(input);
//  assign(output,'C.out');rewrite(output);
  readln(n,m);
  for i:=1 to n do read(a[i]);readln;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then
        begin
          t:=a[i];a[i]:=a[j];a[j]:=t;
        end;
  fillchar(b,sizeof(b),0);k:=0;
  for i:=1 to m do
    begin
      readln(s1);p:=-1;
      for j:=1 to k do
        if s[j]=s1 then
          begin
            p:=j;break;
          end;
      if p=-1 then
        begin
          inc(k);s[k]:=s1;b[k]:=1;
        end else inc(b[p]);
    end;
  for i:=1 to k-1 do
    for j:=i+1 to k do
      if b[i]<b[j] then
        begin
          t:=b[i];b[i]:=b[j];b[j]:=t;
        end;
  t:=0;for i:=1 to k do inc(t,b[i]*a[i]);write(t,' ');
  t:=0;for i:=1 to k do inc(t,b[i]*a[n-i+1]);writeln(t);
//  close(input);close(output);
end.