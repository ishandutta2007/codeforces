
var i, n, cur : longint;
    a : array[0 .. 123456] of longint;
    
begin
  read(n);
  for i := 1 to n do begin  
    read(a[i]);
  end;
  cur := 1;
  for i := 1 to n do begin
    while (cur < i) do begin
      write('R');
      inc(cur);
    end;
    while (a[i] > 0) do begin
      dec(a[i]);
      write('P');
      if (i + 1 <= n) then write('RL') else write('LR');
    end;
  end;
end.