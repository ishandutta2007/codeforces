var s,t,ans:ansistring;
    n,m,i,j,k,l,r:longint; h:char;
  begin
    readln(s);
    //s:=s+' ';
    for i:=0 to length(s) do
     for h:='a' to 'z' do
      begin
        insert(h,s,i+1);
        k:=0;
        //if (i=length(s)-1) and (h='r') then writeln(s);
        for j:=1 to length(s) div 2 do
         if s[j]<>s[length(s)-j+1] then inc(k);
        if k=0 then begin writeln(s); halt; end;
        delete(s,i+1,1);
      end;
    writeln('NA');
  end.