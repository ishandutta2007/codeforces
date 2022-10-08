var t,n,m,k:longint;
begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  readln(t,k);inc(k);
  for t:=1 to t do
    begin
      readln(m,n);
      if n>m then
        begin
          n:=n xor m;m:=n xor m;n:=n xor m;
        end;
      if k>2 then
        if (n mod k=0) or (odd(n div k) xor odd(m+n)) then writeln('+') else writeln('-') else
        if (n mod k=0) or odd(m+n) then writeln('+') else writeln('-');
    end;
  close(input);close(output);
end.