var n,m,i,j,k,l,r:longint;
    a,b,c,d:array[1..100]of longint;
    s,t:ansistring;
    h,q,h1:char;
  begin
    readlN(s);
    readlN(t);
    readln(n);
    for i:=1 to n do
     begin
       readln(l,q,h,q,r,q,h1);
       if h='h' then
        begin
          if (h1='r') and (a[r]<>-1) then begin writeln(s,' ',r,' ',l);
                                               a[r]:=-1; end;
          if (h1='y') AND (A[R]=1) THEN Begin writeln(s,' ',r,' ',l);
                                      a[r]:=-1; end else
          if (h1='y') and (a[r]<>-1) then inc(a[r]);
        end else
        begin
          if (h1='r') and (b[r]<>-1) then begin writeln(t,' ',r,' ',l);
                                               b[r]:=-1; end;
          if (h1='y') AND (b[R]=1) THEN Begin writeln(t,' ',r,' ',l);
                                      b[r]:=-1; end else
          if (h1='y') and (b[r]<>-1) then inc(b[r]);
        end;
     end;
  end.