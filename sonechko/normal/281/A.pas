var s:ansistring;
  begin
    readlN(s);
    if s[1] in ['a'..'z'] then s[1]:=chr(ord(s[1])-32);
    writeln(s);
  end.