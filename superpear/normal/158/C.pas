var n,i,j,top,ls:longint;
    ch:char;
    s,sc,k:ansistring;
    st:array[0..1000] of ansistring;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(ch);
      if ch='p' then
        begin
          readln;
          sc:='/';
          for j:=1 to top do
            sc:=sc+st[j]+'/';
          writeln(sc);
        end
      else
        begin
          read(ch);read(ch);
          readln(s);
          if s[1]='/' then
            begin
              delete(s,1,1);
              top:=0;
            end;
          s:=s+'/';
          k:='';
          ls:=length(s);
          for j:=1 to ls do
            if s[j]='/' then
              begin
                if k='..' then dec(top) else
                  begin
                    inc(top);
                    st[top]:=k;
                  end;
                k:='';
              end
            else
              k:=k+s[j];
        end;
    end;
end.