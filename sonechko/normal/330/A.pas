type rec=record
  pp:longint;
  rr:longint;
end;
var n,m,i,j,k,l,r:longint; h:char;
    a:array[1..10,1..10]of rec;
  begin
    readln(n,m);
    for i:=1 to n do
     begin
       for j:=1 to m do
        begin
          read(h);
          if h='S' then
           begin
            for l:=1 to n do
             a[l,j].pp:=1;
            for r:=1 to m do
             a[i,r].rr:=1;
           end;
        end;
       readln;
     end;
     l:=0;
    for i:=1 to n do
     for j:=1 to m do
      if not((a[i,j].pp=1) and (a[i,j].rr=1)) then inc(L);
    writeln(l);
  end.