var ans,n,m,i,j,k,l,r:longint;
    ar:array[1..50]of longint;
  begin
    readln(n,m);
    for i:=1 to n do
     begin
       read(k);r:=maxlongint;
       for j:=1 to k do
        begin
          read(l);
          //r:=maxlongint;
          if l<r then r:=l;
        end;
       if m>r then begin inc(ans); ar[ans]:=I; END;
     end;
    writeln(ans);
    for I:=1 to ans do
     write(ar[i],' ');
    writeln;
  end.