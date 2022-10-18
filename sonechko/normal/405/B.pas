var s,h:ansistring;
    n,m,k,l,r,i,j,p:longint;
    a:array[1..100000]of longint;
  begin
    readln(n);
    readln(s);
    p:=0;
    for i:=1 to n do
     a[i]:=0;
    for i:=1 to n do
     begin
       if s[i]='L' then
        begin
          k:=0;
          a[i]:=-1;
          for j:=i-1 downto 1 do
           begin
            if s[j]='.' then a[j]:=-1;
            if s[j]='R' then begin k:=j; break; end;
            if s[j]='L' then break;
           end;
          if k<>0 then
           begin
             l:=k;
             r:=i;
             while (r<>0) do
              begin
                if l=r then a[l]:=1;
                if l>r then break;
                inc(l);
                dec(r);
              end;
           end;
        end;
       if s[i]='R' then
        begin
          k:=0;
          a[i]:=-1;
          for j:=i+1 to n do
           begin
            if s[j]='.' then a[j]:=-1;
            if s[j]='R' then break;
            if s[j]='L' then begin k:=j; break; end;
           end;
          if k<>0 then
           begin
             l:=i;
             r:=k;
             while (l<>0) do
              begin
                if l=r then a[l]:=1;
                if l>r then break;
                inc(l);
                dec(r);
              end;
           end;
        end;
     end;
    k:=0;
    for i:=1 to n do
     if (a[i]=0) or (a[i]=1) then inc(k);
    writeln(k);
  end.