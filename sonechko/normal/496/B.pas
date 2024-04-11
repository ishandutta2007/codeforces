var n,m,i,j,k,l,r,p,mm:longint;
    s,t,d:ansistring;
    a:array[1..1000]of ansistring;
   begin
     readln(n);
     readln(s);
     l:=0;
     for i:=2 to length(s) do
      if s[i]<>s[i-1] then l:=1;
     if l=0 then begin for i:=1 to length(s) do write(0); writeln; halt; end;
     l:=0;if (s[1]=s[n]) then
      begin
        k:=0;
        for i:=n downto 2 do
         if s[i]<>s[i-1] then begin k:=i; break; end;
        if k<>0 then
         begin
          t:=copy(s,k,n);
          delete(s,k,n);
          s:=t+s;
         end;
      end;
     k:=1;
     for i:=2 to n do
      if s[i]=s[i-1] then inc(k) else
       begin
       if k>l then l:=k;
       k:=1;
       end;
     k:=1;
     r:=1;
     for i:=2 to n do
      if s[i]=s[i-1] then inc(k) else
       begin
        if k=l then
         begin
            d:=s;
            t:=copy(s,r,n);
            delete(s,r,n);
            s:=t+s;
            inc(mm);
            a[mm]:=s;
            s:=d;
         end;
        k:=1;
        r:=i;
       end;
        if k=l then
         begin
            d:=s;
            t:=copy(s,r,n);
            delete(s,r,n);
            s:=t+s;
            inc(mm);
            a[mm]:=s;
            s:=d;
         end;
     for j:=1 to mm do
      begin
        s:=a[j];
        val(s[1],l,p);
        r:=10-l;
        for i:=1 to n do
         begin
           val(s[i],l,p);
           l:=l+r;
           if l>9 then l:=l-10;
           str(l,d);
           s[i]:=d[1];
         end;
        a[j]:=s;
      end;
     l:=1;
     for i:=1 to mm do
      if a[i]<a[l] then l:=i;
     writeln(a[l]);
   end.