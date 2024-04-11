var n,m,l:longint;
 begin
  read(n,m);
  while (n>0) and (m>0) do
   begin
     inc(l);
     if n>m then begin n:=n-2; m:=m-1; end else
     if m>n then begin m:=m-2; n:=n-1; end else
     if (n=1) and (m=1) then begin l:=l-1; break; end else
     begin n:=n-2; m:=m-1; end;
   end;
  writeln(l);
 end.