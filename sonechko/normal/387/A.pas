var l,r,n,h,m,hh,mm,x,t,k,ans,p:longint;
    s:string;
  begin
    readln(s);
    val(copy(s,1,2),l,p);
    val(copy(s,4,2),r,p);
    readln(s);
    val(copy(s,1,2),h,p);
    val(copy(s,4,2),m,p);
    l:=l+24;
    l:=l*60+r;
    h:=h*60+m;
    l:=l-h;
    t:=l div 60;
    r:=l mod 60;
    if t>=24 then t:=t-24;
    if t<10 then write('0',t,':') else write(t,':');
    if r<10 then writeln('0',r) else writeln(r);

  end.