var n,m,i,j,k,ans,l,r:longint;
    s,t:ansistring;
    ch:char;
  begin
    readln(n,m);
    readln(s);
    for i:=1 to n do
     if ((i=1) and (s[1]='.')) or ((s[i]='.') and (s[i-1]<>'.')) then inc(l);
    for i:=1 to n do
     if s[i]='.' then inc(r);
     //writeln(l,' ',r);
    for i:=1 to m do
     begin
       readln(t);
       val(copy(t,1,length(t)-2),k);
       ch:=t[length(t)];
       if (s[k]='.') and (ch<>'.') then
        begin
          dec(r);
          if (s[k-1]<>'.') and (s[k+1]<>'.') then dec(l) else
          if (s[k-1]='.') and (s[k+1]='.') then inc(l);
        end else
       if (s[k]<>'.') and (ch='.') then
        begin
          inc(r);
          if (s[k-1]='.') and (s[k+1]='.') then dec(l) else
          if (s[k-1]<>'.') and (s[k+1]<>'.') then inc(l);
        end;
       s[k]:=ch;
       writeln(r-l);
     end;
  end.