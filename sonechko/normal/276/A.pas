uses math;
var n,m,l,r,k,ans,i,j:longint;
  begin
    read(m,k);
    ans:=-maxlongint;
    for i:=1 to m do
     begin
       read(l,r);
       if r>k then ans:=max(ans,l-(r-k)) else ans:=max(ans,l);
     end;
    writeln(ans);
  end.