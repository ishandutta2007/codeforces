var d,s,t:string;
    a:array['0'..'9']of longint;
    i,j,k,ans,l,r:longint;
    h:char;
  begin
    readln(s);
    for i:=1 to length(s) do
     inc(a[s[i]]);
    s:='';
    for h:='0' to '9' do
     for i:=1 to a[h] do
      s:=s+h;
    for i:=1 to length(s) do
     if s[i]<>'0' then begin h:=s[i]; s[i]:=s[1]; s[1]:=h; break; end;
    readln(t);
    if s=t then writeln('OK') else writeln('WRONG_ANSWER');
  end.