var hash,x,y:array[0..100000] of longint;
    n,i,s,c,j:longint;
begin
  readln(n);
  fillchar(hash,sizeof(hash),0);
  for i:=1 to n do
    begin
      readln(x[i],y[i]);
      s:=0;
      for j:=1 to trunc(sqrt(x[i])) do
        if x[i] mod j=0 then
          begin
            c:=j;
            if hash[c]<i-y[i] then inc(s);
            hash[c]:=i;
            c:=x[i] div j;
            if c=j then continue;
            if hash[c]<i-y[i] then inc(s);
            hash[c]:=i;
          end;
      writeln(s);
    end;
end.