var l,s:string;
    i,j,ans,r,n,m,p:longint; k:int64;
  begin
    readln(l);
    for i:=1 to length(l) do
     begin
       val(l[i],n,p);
       if 9-n<n then begin str(9-n,s); l[i]:=s[1]; end;
     end;
    if l[1]='0' then l[1]:='9';
    writeln(l);
  end.