var a,b,c,d,x:int64;
i:longint;
    s:ansistring;
  begin
    readln(a,b,c,d);
    readln(s);
    for i:=1 to length(s) do
     if s[i]='1' then x:=x+a else
     if s[i]='2' then x:=x+b else
     if s[i]='3' then x:=x+c else x:=x+d;
    writeln(x);
  end.