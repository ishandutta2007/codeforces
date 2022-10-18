var n,m,i,j,k,ans,l,r:longint;
function bol(m:longint):boolean;
 var i:longint;
  begin
    if m=1 then exit(false);
    for i:=2 to round(sqrt(m)) do
     if m mod i=0 then exit(false);
    exit(true);
  end;
  begin
    read(n);
    for i:=1 to n do
     if bol(i) then
      begin
       l:=1;
       for j:=1 to n do
        if l*i>n then break else begin inc(ans); l:=l*i; end;
      end;
    writeln(ans);
    for i:=1 to n do
     if bol(i) then
      begin
       l:=1;
       for j:=1 to n do
        if l*i>n then break else begin write(l*i,' '); l:=l*i; end;
      end;
    writeln;
  end.