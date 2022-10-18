var n,m,i,j,k,ans,l,r,b1,b2,b3:longint;
    a1,a2,a3:array[1..100]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       if l<0 then begin inc(b1); a1[b1]:=l; end;
       if l>0 then begin inc(b2); a2[b2]:=l; end;
       if l=0 then begin inc(b3); a3[b3]:=l; end;
     end;
    if (b2=0) then
     begin
       inc(b2,2);
       a2[1]:=a1[b1];
       a2[2]:=a1[b1-1];
       dec(b1,2);
     end;
    if (b1 mod 2=0) then
     begin
       inc(b3);
       a3[b3]:=a1[b1];
       dec(b1);
     end;
    write(b1,' ');
    for i:=1 to b1 do
     write(a1[i],' ');
    writeln;
    write(b2,' ');
    for i:=1 to b2 do
     write(a2[i],' ');
    writeln;
    write(b3,' ');
    for i:=1 to b3 do
     write(a3[i],' ');
    writeln;
  end.