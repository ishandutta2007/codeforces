var s:string;
    i,j,k,l,r:longint;
  begin
    readln(s);
    l:=0;
    r:=0;
    for i:=1 to length(s) do
     if s[i] in ['A'..'Z'] then inc(l) else inc(r);
    if l>r then
     begin
       for i:=1 to length(s) do
        if s[i] in ['a'..'z'] then write(chr(ord(s[i])-32)) else write(s[i]);
     end else
     begin
       for i:=1 to length(s) do
        if s[i] in ['A'..'Z'] then write(chr(ord(s[i])+32)) else write(s[i]);
     end;
    writeln;
 
  end.