var s:ansistring;
    i,l:longint;
  begin
    readln(s);
    for i:=1 to length(s) do
     if s[i] in ['H','Q','9'] then begin writeln('YES'); halt; end;
    writeln('NO');
  end.