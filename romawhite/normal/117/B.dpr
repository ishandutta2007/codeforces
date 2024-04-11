 var n,m,i,j,k,l,s,f,t:integer;
      a,b,c,d,e:integer;
      p:array[1..10000000] of integer;
      begin
      read(a,b,m);
      d:=1000000000;
      if d mod m =0 then begin writeln(2);exit;end;
      k:=d mod m;
      p[1]:=k mod m;
      if a>m then a:=m;
      for i:=2 to a do
        p[i]:=(p[i-1]+k)mod m;
      for i:=1 to a do
        begin
       l:=p[i];
      if l<>0 then l:=m-l;
      if l>b then
          begin
      write(1,' ');
      s:=i;
      f:=0;
      while s<>0 do
            begin
      inc(f);
      s:=s div 10;
            end;
      for j:=1 to 9-f do write(0);
      writeln(i);
      exit;
          end;
        end;
      writeln(2);
      //readln;readln;
      end.