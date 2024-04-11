program B;
var l,h,a:array[1..30] of longint;
    n,p,i,ls,hs:longint;
begin
//  assign(input,'B.in');reset(input);
//  assign(output,'B.out');rewrite(output);
  readln(n,p);ls:=0;hs:=0;
  for i:=1 to n do
    begin
      readln(l[i],h[i]);a[i]:=l[i];
      inc(ls,l[i]);inc(hs,h[i]);
    end;
  if (p<ls) or (p>hs) then writeln('NO') else
    begin
      writeln('YES');
      for i:=1 to n do
        if h[i]-l[i]<=p-ls then
          begin
            a[i]:=h[i];inc(ls,h[i]-l[i]);
          end else
          begin
            inc(a[i],p-ls);
            ls:=p;break;
          end;
      for i:=1 to n-1 do write(a[i],' ');writeln(a[n]);
    end;
//  close(input);close(output);
end.