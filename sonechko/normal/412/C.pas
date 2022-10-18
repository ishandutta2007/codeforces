var n,m,i,j,k,l,r:longint;
    s,s1:ansistring;
    a:array[1..100000]of ansistring;
    b:array[1..100000]of longint;
  begin
    readln(n);
    for i:=1 to n do
     readln(a[i]);
    s:=a[1];
    for j:=1 to n do
     begin
       s1:=a[j];
       for i:=1 to length(s) do
        if s[i]='[' then s[i]:='[' else
        if (s[i] in ['?','>']) and (s1[i] in ['?','>']) then s[i]:='>' else
        if (s[i] in ['a'..'z']) and (s1[i] in ['?','>']) then s[i]:=s[i] else
        if (s[i] in ['?','>']) and (s1[i] in ['a'..'z']) then s[i]:=s1[i] else
        if s[i]<>s1[i] then s[i]:='[';
     end;
    for i:=1 to length(s) do
     if s[i]='>' then s[i]:='x' else if s[i]='[' then s[i]:='?';
    writeln(s);
  end.