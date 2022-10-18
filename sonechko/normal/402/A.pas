var a,b,v,k,i,j,x,y,z,z1:longint;
  begin

    read(k,a,b,v);
    x:=k-1;
    y:=(x+1)*v;
    z:=b div x;
    z1:=b mod x;
    k:=0;
    while (a>0)  do
     begin
       if b>z1 then begin a:=a-y; inc(k); b:=b-x; end else begin a:=a-((b+1)*v);
       inc(k); b:=b-(b mod x); end;
     end;
    writeln(k);
  end.