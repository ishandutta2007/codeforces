var l,r,i,j,k,n,m,p:longint;
    s:ansistring;       ch:char;
  begin
    readln(s);
    for i:=1 to length(s) do
     if s[i] in ['0','2','4','6','8'] then k:=i;
    if k=0 then begin writeln('-1'); halt; end;
    val(s[length(s)],r,p);     j:=k;
    for i:=1 to length(s) do
     begin
      val(s[i],l,p);
      if (l mod 2=0) and (l<r) then begin j:=i; break; end;
     end;
    ch:=s[j];
    s[j]:=s[length(s)];
    s[length(s)]:=ch;
    writeln(s);
  end.