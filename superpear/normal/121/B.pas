var ls,k,j,i:longint;
    c:string;
    s:array[0..100000] of char;
    c1,c2:ansistring;
begin
  readln(ls,k);
  for i:=1 to ls do read(s[i]);
  for i:=1 to ls-1 do
    begin
      if (i mod 2=1) and (i+2<=ls) then
        begin
          c:=s[i]+s[i+1]+s[i+2];
          if c='447' then
            begin
              c1:='';
              for j:=1 to i-1 do c1:=c1+s[j];
              c2:='';
              for j:=i+3 to ls do c2:=c2+s[j];
              if k mod 2=0 then writeln(c1+'447'+c2)
                           else writeln(c1+'477'+c2);
              halt;
            end;
          if c='477' then
            begin
              c1:='';
              for j:=1 to i-1 do c1:=c1+s[j];
              c2:='';
              for j:=i+3 to ls do c2:=c2+s[j];
              if k mod 2=1 then writeln(c1+'447'+c2)
                           else writeln(c1+'477'+c2);
              halt;
            end;
        end;
      if (i mod 2=1) and (s[i]='4') and (s[i+1]='7') then
        begin
          if k=0 then break;
          s[i+1]:='4';
          dec(k);
        end;
      if (i mod 2=0) and (s[i]='4') and (s[i+1]='7') then
        begin
          if k=0 then break;
          s[i]:='7';
          dec(k);
        end;
    end;
  for i:=1 to ls do write(s[i]);writeln;
end.