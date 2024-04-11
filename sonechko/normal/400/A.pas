var s,w:string;
    n,t,i,j,k:longint;

  begin
    readln(n);
    for i:=1 to n do
     begin
       readln(s);
       k:=0;
       t:=0;
       w:='';
       if (s[1]='X') or (s[2]='X') or (s[3]='X') or (s[4]='X') or (s[5]='X') or (s[6]='X') or (s[7]='X') or (s[8]='X') or (s[9]='X') or (s[10]='X') or (s[11]='X') or (s[12]='X') then
        begin
          inc(k);
          w:=w+'1x12 ';
        end;
        for j:=1 to length(s) div 2 do
        if (s[j]='X') and (s[j+6]='X') then
         begin
           inc(k);
           w:=w+'2x6 ';
           break;
         end;
       for j:=1 to length(s) div 3 do
        if (s[j]='X') and (s[j+4]='X') and (s[j+8]='X') then
         begin
           inc(k);
           w:=w+'3x4 ';
           break;
         end;
       for j:=1 to length(s) div 4 do
        if (s[j]='X') and (s[j+3]='X') and (s[j+6]='X') and (s[j+9]='X') then
         begin
           inc(k);
           w:=w+'4x3 ';
           break;
         end;

         if ((s[1]='X') and (s[3]='X') and (s[5]='X') and (s[7]='X') and (s[9]='X') and (s[11]='X'))
       or ((s[2]='X') and (s[4]='X') and (s[6]='X') and (s[8]='X') and (s[10]='X') and (s[12]='X')) then
        begin
          inc(k);
          w:=w+'6x2 ';
        end;
        if (s[1]='X') and (s[2]='X') and (s[3]='X') and (s[4]='X') and (s[5]='X') and (s[6]='X') and (s[7]='X') and (s[8]='X') and (s[9]='X') and (s[10]='X') and (s[11]='X') and (s[12]='X') then
         begin
           inc(k);
           w:=w+'12x1 ';
         end;
       write(k,' ');
       writeln(w);
     end;
  end.