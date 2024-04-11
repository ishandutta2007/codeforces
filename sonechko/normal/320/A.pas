var s:string;
    i,j,k,l,r,n,m:longint;
  begin
    readln(s);
    i:=1;
    s:=s+'  ';
    while i<>length(s) do
     begin
         if s[i]=' ' then break;
       if s[i]<>'1' then begin writeln('NO'); halt; end;
       if (s[i+1]='4') and (s[i+2]='4') then inc(i,3) else
       if (s[i+1]='4') then inc(i,2) else
       if (s[i]='1') then inc(i,1);
     end;
    writeln('YES');
  end.