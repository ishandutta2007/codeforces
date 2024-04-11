var i,k,n,m,l:longint;
    ch:char;
    s:string;
  begin
   readln(n,ch,s);
   if s[4]='w' then
    begin
     if (n=5) or (n=6) then WriteLn(53) else WriteLn(52);
    end;
   if s[4]='m' then
    begin
     if (n<30) then WriteLn(12) else
     if (n=30) then WriteLn(11) else
     if (n=31) then WriteLn(7);
     end;
  end.