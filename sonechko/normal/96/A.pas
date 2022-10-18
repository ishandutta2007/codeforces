var s:ansistring;
 function tt(t:ansistring):boolean;
  var i,j,k,l,r:longint;
   begin
     k:=1;
     l:=1;
     for i:=2 to length(t) do
      if t[i]=t[i-1] then inc(k) else begin if k>l then l:=k; k:=1; end;
     if k>l then l:=k;
     if l>=7 then tt:=true else tt:=false;
   end;
  begin
    readln(s);
    if tt(s) then writeln('YES') else writeln('NO');
  end.