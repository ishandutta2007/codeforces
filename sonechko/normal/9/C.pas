var s:string;
    n,m,i,j,k,ans,l,r:longint;
procedure rec(t:string);
  begin
    if (length(t)>length(s)) or ((length(t)=length(s)) and (t>s)) then exit;
    inc(ans);
    rec(t+'1');
    rec(t+'0');
  end;
  begin
    readln(s);
    ans:=0;
    rec('1');
    writeln(ans);
  end.