var n,x,y,h:int64;
    i:longint;
  begin
    read(n,x,y);
    h:=y-n+1;
    if h<1 then begin writeln('-1'); halt; end;
    if h*h+(n-1)>=x then begin
    writeln(h);
    for i:=1 to n-1 do writeln(1); end else writeln('-1');
  end.