var a:array[1..1000] of boolean;
    n,i,s,k,tt,j,t:longint;
    c:char;
begin
  readln(n);tt:=0;
  for i:=1 to n do
    begin
      read(c);
      if c='H' then a[i]:=true else a[i]:=false;
      if c='H' then inc(tt);
    end;
  s:=maxlongint;
  for i:=1 to n do
    begin
      k:=i;t:=0;
      for j:=1 to tt do
        begin
          if not a[k] then inc(t);
          inc(k);if k>n then k:=1;
        end;
      if t<s then s:=t;
    end;
  writeln(s);
end.