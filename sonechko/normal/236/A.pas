var s:string;
    a:array['a'..'z'] of longint;
    i,k:longint;
  begin
    readln(s);
    k:=0;
    for i:=1 to length(s) do
     begin
       inc(a[s[i]]);
       if a[s[i]]=1 then inc(k);
     end;
    if k mod 2=0 then writeln('CHAT WITH HER!') else writeln('IGNORE HIM!');
  end.