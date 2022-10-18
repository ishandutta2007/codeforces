var a,b,c,d:Longint;
 function bad(a,b,c:longint):boolean;
  begin
    if (a+b>c) and (b+c>a) and (c+a>b) then bad:=true else bad:=false;
  end;
 function bad1(a,b,c:longint):boolean;
  begin
    if (a+b=c) or (b+c=a)or (a+c=b) then bad1:=true else bad1:=false;
  end;
  begin
    read(a,b,c,d);
    if (bad(a,b,c)) or (bad(a,b,d)) or (bad(b,c,d)) or (bad(a,c,d)) then
     writeln('TRIANGLE') else
    if (bad1(a,b,c)) or (bad1(a,b,d)) or (bad1(b,c,d)) or (bad1(a,c,d)) then
     writeln('SEGMENT') else writeln('IMPOSSIBLE');
  end.