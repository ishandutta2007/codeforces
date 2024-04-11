var st:ansistring;
    n,k,i,j,u,flag,ef,ff,gg:longint;
    f:array[0..10000,0..10] of string[100];
    a:array[0..10000] of longint;
    e:array[0..10] of string[10];

begin
  readln(n,k);
  flag:=1;
  for i:=1 to n do
    begin
      for j:=1 to 4 do
        begin
          readln(st);
          ef:=0;
          for u:=length(st) downto 1 do
            if (st[u]='a') or (st[u]='e') or (st[u]='i') or (st[u]='o') or (st[u]='u') then
              begin
                inc(ef);
                if ef=k then
                  begin
                    st:=copy(st,u,length(st)-u+1);
                    break;
                  end;
              end;
          if ef<k then
            begin
              flag:=0;
              break;
            end;
          f[i,j]:=st;
        end;
      if flag=0 then break;
    end;
  if flag=0 then
    writeln('NO')
  else
    begin
      //1:aabb 2:abab 3:abba 4:aaaa
      e[1]:='aabb';
      e[2]:='abab';
      e[3]:='abba';
      flag:=1;
      for i:=1 to n do
        begin
          a[i]:=0;
          if (f[i,1]=f[i,2]) and (f[i,2]=f[i,3]) and (f[i,3]=f[i,4]) then
            a[i]:=4
          else
            if (f[i,1]=f[i,2]) and (f[i,3]=f[i,4]) then a[i]:=1
            else
              if (f[i,1]=f[i,3]) and (f[i,2]=f[i,4]) then a[i]:=2
              else
                if (f[i,1]=f[i,4]) and (f[i,2]=f[i,3]) then a[i]:=3;
          if a[i]=0 then
            begin
              flag:=0;
              break;
            end;
        end;
      if flag=0 then writeln('NO') else
        begin
          ff:=1;
          for i:=1 to n do
            if a[i]<>4 then
              begin
                ff:=0;
                break;
              end;
          if ff=1 then writeln('aaaa') else
            begin
              ff:=1;
              gg:=-1;
              for i:=1 to n do
                if a[i]<>4 then
                  begin
                    if (gg<>-1) and (gg<>a[i]) then
                      begin
                        ff:=0;
                        break;
                      end;
                    gg:=a[i];
                  end;
              if ff=0 then
                writeln('NO')
              else
                writeln(e[gg]);
            end;
        end;
    end;
end.