var n,k,i,l:longint;
  begin
    read(n,k);
    l:=k+1;
    for i:=1 to k+1 do
     begin
       write(l,' ');
       dec(l);
     end;
    for i:=k+2 to n do
     write(i,' ');
  end.