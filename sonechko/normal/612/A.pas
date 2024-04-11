uses math;
var n,m,i,j,k,ans,l,r:longint;
    s:ansistring;
    a:array[-100..101]of boolean;
    b:array[-100..101]of string;
  begin
    readln(n,m,k);
    readln(s);
    fillchar(a,sizeof(a),false);
    a[0]:=true;
    for i:=min(m,k) to n do
     if (a[i-m]=true) or (a[i-k]=true) then a[i]:=true else a[i]:=false;
    if a[n]=false then writeln('-1') else
     begin
       i:=n;
       ans:=0;
       while (i>0) do
        begin
          //writeln(i);
          if (i-m>=0) and (a[i-m]=true) then begin inc(ans); b[ans]:=copy(s,i-m+1,m); i:=i-m; end else
          begin inc(ans); b[ans]:=copy(s,i-k+1,k); i:=i-k; end;              ;
        end;
       writeln(ans);
       for i:=ans downto 1 do
        writeln(b[i]);
     end;
  end.