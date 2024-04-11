var n,m,i,j,k,ans,l,r:longint;
    ch:char;
    s,t:ansistring;
  begin
    readln(n);
    while not eof do
     begin
       read(ch);
       if ch=' ' then
        begin
          if (k=0) and (r=0) and (l=1) then begin writeln('0'); halt; end;
          if (k<>0) then s:=t;
          if (k=0) and (r<>1) then s:=t;
          if (k=0) and (r=1) then ans:=ans+l;
          k:=0;
          r:=0;
          t:='';
          l:=0;
        end else
       if ch in ['0'..'9'] then begin
        t:=t+ch;
       if ch='0' then inc(l) else
       if ch='1' then inc(r) else inc(k); end;
     end;
     if (k=0) and (r=0) and (l=1) then begin writeln('0'); halt; end;
     if (k<>0) then s:=t;
          if (k=0) and (r<>1) then s:=t;
          if (k=0) and (r=1) then ans:=ans+l;
    if s='' then s:='1';
    write(s);
    for i:=1 to ans do
     write('0');
    writeln;
  end.