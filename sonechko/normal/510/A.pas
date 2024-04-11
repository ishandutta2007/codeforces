var n,m,i,j,k,ans,l,r:longint;
 begin
   read(n,m);
   k:=0;
   l:=1;
   for i:=1 to n do
    begin
      if k=0 then
       begin
        for j:=1 to m do
         write('#');
        writeln;
        k:=1;
       end else
      if (l=1) then
       begin
         for j:=1 to m-1 do
          write('.');
         writeln('#');
         k:=0;
         l:=2;
       end else
      if (l=2) then
       begin
         write('#');
         for j:=2 to m do
          write('.');
         writeln;
         k:=0;
         l:=1;
       end;
    end;
 end.