var a,b:array[0..200002]of int64;
    k,ans,l,r,n,m:int64;
    i,j:longint;
    s,t:ansistring;
  begin
    readln(s);
    readln(t);
    for i:=1 to length(t) do
     if t[i]='0' then begin b[i]:=b[i-1]+1; a[i]:=a[i-1];end else
      begin a[i]:=a[i-1]+1; b[i]:=b[i-1]; end;
    for i:=1 to length(s) do
     begin
       l:=i;
       r:=length(t)-length(s)+l;
       if s[i]='1' then ans:=ans+b[r]-b[l-1] else ans:=ans+a[r]-a[l-1];
     end;
    writeln(ans);
  end.