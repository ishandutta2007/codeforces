const a:array[1..5]of string=('Sheldon','Leonard','Penny','Rajesh','Howard');
var n,l:int64;
 begin
   l:=1;
   read(n);
   if n<=5 then writeln(a[n]) else
    begin
      while true do
       begin
         if l*5>=n then break;
         n:=n-l*5;
         l:=l*2;
       end;
      if n<=l then writeln(a[1]) else
      if n<=l*2 then writeln(a[2]) else
      if n<=l*3 then writeln(a[3]) else
      if n<=l*4 then writeln(a[4]) else writeln(a[5]);
    end;
 end.