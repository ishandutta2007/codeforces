var s:ansistring;
    i,j,k,l,r:longint;
  begin
    readln(s);
    if pos('h',s)=0 then begin writeln('NO'); halt; end;
    delete(s,1,pos('h',s));
    if pos('e',s)=0 then begin writeln('NO'); halt; end;
    delete(s,1,pos('e',s));
    if pos('l',s)=0 then begin writeln('NO'); halt; end;
    delete(s,1,pos('l',s));
    if pos('l',s)=0 then begin writeln('NO'); halt; end;
    delete(s,1,pos('l',s));
    if pos('o',s)=0 then writeln('NO') else writeln('YES');
  end.