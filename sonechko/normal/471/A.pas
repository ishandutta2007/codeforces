uses math;
var i,k,l,j:longint;
    a,c,d:array[1..6]of longint;
  begin
    for i:=1 to 6 do
     read(a[i]);
    for I:=1 to 6 do
     for j:=i+1 to 6 do
      if a[i]>a[j] then begin k:=a[i]; a[i]:=a[j]; a[j]:=k; end;
    k:=0;
    for i:=1 to 3 do
     begin
       if (a[i]=a[i+1]) and (a[i]=a[i+2]) and (a[i]=a[i+3]) then
        begin
         inc(k);
         if i=1 then
          begin
            c[k]:=min(a[5],a[6]);
            d[k]:=max(a[5],a[6]);
          end;
         if i=2 then
          begin
            c[k]:=min(a[1],a[6]);
            d[k]:=max(a[1],a[6]);
          end;
         if i=3 then
          begin
            c[k]:=min(a[1],a[2]);
            d
            [k]:=max(a[1],a[2]);
          end;
        end;
     end;
    if k=0 then begin writeln('Alien'); halt; end;
    for i:=1 to k do
     begin
       l:=0;
       if (c[i]<d[i]) or (c[i]>d[i]) then begin writeln('Bear'); halt; end;
       if (c[i]=d[i]) then begin writeln('Elephant'); halt; end;
     end;
    writeln('Alien');
  end.