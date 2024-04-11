var s,s1:ansistring;
    a,b:array['a'..'z']of longint;
    i,j,k:longint;
    h:char;
  begin
    readln(s);
    readln(s1);
    for i:=1 to length(s) do
     inc(a[s[i]],1);
    for i:=1 to length(s1) do
     inc(b[s1[i]],1);
    k:=0;
    for h:='a' to 'z' do
     begin
      if (a[h]=0) and (b[h]<>0) then begin writeln('-1'); halt; end;
      if (a[h]=b[h]) then k:=k+a[h];
      if (a[h]>b[h]) then k:=k+b[h];
      if (a[h]<b[h]) then
       begin
         k:=k+(a[h]-1);
         k:=k+1;
       end;
     end;
    writeln(k);
  end.