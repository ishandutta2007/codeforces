var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    if n mod 4>=2 then writeln('-1') else
    begin
      l:=2;
      r:=n;
      for i:=1 to n div 4 do
       begin
         write(l,' ',r,' ');
         l:=l+2;
         r:=r-2;
       end;
      if n mod 2=1 then write(n div 2+1,' ');
      l:=n div 2-1;
      r:=n div 2+1+n mod 2;
      for i:=1 to n div 4 do
       begin
         write(l,' ',r,' ');
         l:=l-2;
         r:=r+2;
       end;
      writeln;
    end;
  end.