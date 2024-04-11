var n,m,k,l,r,i,j:longint;
 function nsd(a,b:longint):longint;
  begin
    while (a>0) and (b>0) do
     if a>b then a:=a mod b else b:=b mod a;
    nsd:=a+b;
  end;
  begin
    read(n,m,l);
    k:=1;
    while true do
     begin
       if k mod 2=1 then
        begin
          if nsd(n,l)>l then begin writeln('1'); halt; end;
          l:=l-nsd(n,l);
        end else
        begin
          if nsd(m,l)>l then begin writeln('0'); halt; end;
          l:=l-nsd(m,l);
        end;
       inc(k);
     end;
  end.