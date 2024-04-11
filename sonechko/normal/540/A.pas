uses math;
var n,m,i,j,k,ans,l,r,k1,k2:longint;
    s,t:ansistring;
  begin
    readln(n);
    readln(s);
    readln(t);
    for i:=1 to n do
     begin
       val(s[i],l);
       val(t[i],r);
       if l>r then k1:=10-l+r else k1:=r-l;
       if l<r then k2:=l+10-r else k2:=l-r;
       ans:=ans+min(k1,k2);
     end;
    writeln(ans);
  end.