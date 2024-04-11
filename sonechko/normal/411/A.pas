var s:string;
    i,n,j,k1,k2,k3:longint;
  begin
    readln(s);
    for i:=1 to length(s) do
     if s[i] in ['a'..'z'] then inc(k1) else
     if s[i] in ['A'..'Z'] then inc(k2) else
     if s[i] in ['0'..'9'] then inc(k3);
    if (length(s)>=5) and (k1>0) and (k2>0) and (k3>0) then writeln('Correct')
    else writeln('Too weak');
  end.