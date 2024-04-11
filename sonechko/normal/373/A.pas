var n,m,i,j,k,ans,l,r:Longint;
    a:array[1..9]of longint;
    g:char;
  begin
    readln(n);
    for i:=1 to 4 do
     begin
       for j:=1 to 4 do
        begin
          read(g);
          if g<>'.' then val(g,l);
          if g<>'.' then inc(a[l]);
        end;
       readln;
     end;
    for i:=1 to 9 do
     if a[i]>n*2 then begin writeln('NO');
     halt;
      end;
     writeln('YES');
  end.