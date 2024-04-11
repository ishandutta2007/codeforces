var i,q:longint;
    n,k,c,pp:int64;
    a:array[0..10000] of int64;

begin
  readln(n,k,q);
  for i:=1 to q do read(a[i]);
  if n mod 2=1 then
    begin
      c:=(n+1) div 2;
      c:=k-c;
      if c>0 then
        pp:=c*2+1
      else
        pp:=0;
    end
  else
    begin
      c:=n div 2;
      c:=k-c;
      if c>0 then pp:=c*2 else pp:=0;
    end;
  for i:=1 to q do
    begin
      a[i]:=n+1-a[i];
      if k=0 then write('.') else
        begin
          if a[i]=1 then write('X') else
            if n mod 2=1 then
              begin
                if (a[i]<=pp) or ((a[i] mod 2=0) and (a[i] div 2<k)) then
                  write('X')
                else
                  write('.');
              end
            else
              begin
                if (a[i]<=pp) or ((a[i] mod 2=1) and (a[i]<=k*2-1)) then
                  write('X')
                else
                  write('.');
              end;
        end;
    end;
  writeln;
end.