var s,t:ansistring;
    n,m,i,j,k,ans,l,r:longint;
    ch:char;
  begin
    readln(n,m);
    readln(s);
    for i:=1 to length(s) do
     begin
       l:=ord(s[i])-97;
       r:=122-ord(s[i]);
       if (l>r) then
       begin
         if (l<m) then begin t:=t+'a'; m:=m-l; end else
         if (m=0) then t:=t+s[i] else
         begin
           k:=0;
           for ch:=s[i] downto 'a' do
            if k=m then begin t:=t+ch; break; end else k:=k+1;
           m:=0;
         end;
       end else
       begin
         if (r<m) then begin t:=t+'z'; m:=m-r; end else
         if (m=0) then t:=t+s[i] else
          begin
            k:=0;
            for ch:=s[i] to 'z' do
            if k=m then begin t:=t+ch; break; end else k:=k+1;
            m:=0;
          end;

       end;
     end;
    if m=0 then writeln(t) else writeln(-1);
  end.