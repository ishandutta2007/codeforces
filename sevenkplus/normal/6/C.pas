program C;
var a:array[1..100000] of longint;
    l,r,l1,r1,i,n,s:longint;
begin
//  assign(input,'C.in');reset(input);
//  assign(output,'C.out');rewrite(output);
  readln(n);s:=0;
  for i:=1 to n do
    begin
      read(a[i]);inc(s,a[i]);
    end;
  l:=0;r:=n+1;l1:=0;r1:=0;
  while l1+r1<s do
    if l1=r1 then
      if r-l=2 then
        begin
          inc(l);inc(l1,a[l]);
        end else
        begin
          inc(l);inc(l1,a[l]);dec(r);inc(r1,a[r]);
        end else
    if l1>r1 then
      begin
        dec(r);inc(r1,a[r]);
      end else
      begin
        inc(l);inc(l1,a[l]);
      end;
  writeln(l,' ',n-l);
//  close(input);close(output);
end.