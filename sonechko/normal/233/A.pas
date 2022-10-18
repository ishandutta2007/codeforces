var n,i:longint;
  begin
    read(n);
    if n mod 2=1 then begin writeln('-1'); halt; end;
    for i:=n downto 1 do
     write(i,' ');
    writeln;
  end.