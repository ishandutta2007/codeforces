var n,m,k,l,r,ans,i,j:longint;
  begin
    read(n,m,k);
    for i:=1 to n do
     begin
       read(l);
       if l=1 then begin if m>0 then m:=m-1 else ans:=ans+1; end;
       if l=2 then begin if k>0 then dec(k) else
                         if m>0 then dec(m) else inc(ans); end;
     end;
    writeln(ans);
  end.