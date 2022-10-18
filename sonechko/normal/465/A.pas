var n,i,j:longint;
    s:string;
  begin
    readln(n);
    readln(s);
    for i:=1 to n do
     if s[i]='0' then begin writeln(i); halt; end;
    writeln(n);
  end.