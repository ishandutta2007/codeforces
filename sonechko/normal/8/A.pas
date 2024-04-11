var ans1,ans2,i,j,k,ans,l,r,n,m:longint;
    s,t,d:ansistring;
function back(s:ansistring):ansistring;
var t:ansistring;
    i:longint;
  begin
    t:='';
    for i:=1 to length(s) do
     t:=s[i]+t;
    exit(t);
  end;
  begin
    readln(s);
    readln(t);
    readln(d);
    if (pos(t,s)>0) and (pos(d,s)>0)
     then
    begin
      r:=0;
      for i:=1 to length(s) do
       if copy(s,i,length(d))=d then r:=i;
      if pos(t,s)+length(t)<=r then ans1:=1 else ans1:=0;
    end;
    s:=back(s);
    //t:=back(t);
    //d:=back(d);
    if (pos(t,s)>0) and (pos(d,s)>0) then
     begin
      r:=0;
      for i:=1 to length(s) do
       if copy(s,i,length(d))=d then r:=i;
      if (pos(t,s)+length(t)<=r) then ans2:=1;
     end;
    if (ans1=0) and (ans2=0) then writeln('fantasy');
    if (ans1=1) and (ans2=0) then writeln('forward');
    if (ans1=0) and (ans2=1) then writeln('backward');
    if (ans1=1) and (ans2=1) then writeln('both');
  end.