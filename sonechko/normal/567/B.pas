var n,m,i,j,k,ans,l,r:longint;
    a:array[1..1000000]of boolean;
    s:ansistring;
  begin
    readln(n);
    fillchar(a,sizeof(a),false);
    for i:=1 to n do
     begin
       readln(s);
       if s[1]='+' then
        begin
         val(copy(s,3,length(s)-2),l);
         r:=r+1;
         if r>ans then ans:=r;
         a[l]:=true;
        end;
       if s[1]='-' then
        begin
          val(copy(s,3,length(s)-2),l);
          if a[l]=true then begin a[l]:=false; dec(r); end else inc(ans);
        end;
        //2writeln(ans);
     end;
    writeln(ans);
  end.