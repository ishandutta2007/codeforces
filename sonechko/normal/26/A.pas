var n,m,i,j,k,ans,l,r:longint;
function prost(l:longint):boolean;
 var i:longint;
  begin
    for i:=2 to round(sqrt(l)) do
     if l mod i=0 then exit(false);
    exit(true);
  end;
  begin
    read(n);
    for i:=1 to n do
     begin
       l:=0;
       for j:=2 to round(sqrt(i)) do
        begin
         if (i mod j=0) and (prost(j)) then inc(l);
         if (i mod j=0) and (i div j<>j) and (prost(i div j)) then inc(l);
         if l>2 then break;
        end;
       if l=2 then begin inc(ans); end;
     end;
    writeln(ans);
  end.