var s,t:string;
 i,j,l,r,n:longint;
  begin
   readln(s);
    readln(t);
     n:=length(s);
      while n>=1 do
       if s[n]='z' then begin s[n]:='a'; dec(n); end else
        begin s[n]:=chr(ord(s[n])+1); break; end;
         if s>=t then writeln('No such string') else writeln(s);
          end.