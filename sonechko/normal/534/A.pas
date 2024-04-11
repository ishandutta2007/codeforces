uses math;
var n,m,k,ans,l,r,ll,rr:longint;  i,j:longint;
    a:array[1..5000]of int64;
  begin
    read(n);
    l:=1;
    for i:=1 to n do
     begin
       a[l]:=i;
       inc(l,2);
       if l>n then l:=2;
     end;
    if n<3 then begin writeln('1'); writeln('1'); halt; end;
    if n=3 then begin writeln(2); writeln('1 3'); halt; end;
    if n=4 then begin writeln(4); writeln('3 1 4 2'); halt; end;
    writeln(n);
    for i:=1 to n do
     write(a[i],' ');
    writeln;
  end.