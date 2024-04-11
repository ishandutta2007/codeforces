var m,n,i,flag,num,con,j:longint;
    hash,open:array[0..100000] of longint;
    ch:char;

begin
  readln(n,m);
  fillchar(hash,sizeof(hash),0);
  fillchar(open,sizeof(open),0);
  for i:=1 to m do
    begin
      read(ch);
      readln(num);
      if ch='+' then
        begin
          if open[num]=1 then writeln('Already on') else
            begin
              con:=0;
              flag:=1;
              for j:=2 to trunc(sqrt(num)) do
                if num mod j=0 then
                  begin
                    if hash[j]<>0 then
                      begin
                        flag:=0;
                        con:=hash[j];
                        break;
                      end;
                    if hash[num div j]<>0 then
                      begin
                        flag:=0;
                        con:=hash[num div j];
                        break;
                      end;
                  end;
              if (num<>1) and (hash[num]<>0) then
                begin
                  flag:=0;
                  con:=hash[num];
                end;
              if flag=0 then
                writeln('Conflict with ',con)
              else
                begin
                  writeln('Success');
                  open[num]:=1;
                  for j:=1 to trunc(sqrt(num)) do
                    if num mod j=0 then
                      begin
                        if j<>1 then hash[j]:=num;
                        if num<>j then hash[num div j]:=num;
                      end;
                end;
            end;
        end
      else
        begin
          if open[num]=0 then writeln('Already off') else
            begin
              for j:=1 to trunc(sqrt(num)) do
                if num mod j=0 then
                  begin
                    if j<>1 then hash[j]:=0;
                    if num<>j then hash[num div j]:=0;
                  end;
              open[num]:=0;
              writeln('Success');
            end;
        end;
    end;
end.