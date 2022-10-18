var n,m,i,j,k,ans,l,r:longint;
    a:array[1..1000000]of ansistring;
    s,t:ansistring;
  begin
    readln(n);
    m:=0;
    for j:=1 to n do
     begin
       readln(s);
       if s[1]='p' then
        begin
          for i:=1 to m do
           write(a[i]);
          writeln('/');
        end else
        begin
          delete(s,1,3);
          i:=1;
          if s[1]='/' then m:=0 else s:='/'+s;
          s:=s+'/';
          while length(s)>1 do
           begin
             t:='/';
             delete(s,1,1);
             t:=t+copy(s,1,pos('/',s)-1);
             delete(s,1,pos('/',s)-1);
             if t='/..' then m:=m-1 else begin inc(m); a[m]:=t; end;
           end;
        end;
     end;
  end.