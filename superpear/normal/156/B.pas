var m,n,all,i,num,sum,e1:longint;
    ch:char;
    a1,a2,data,ok:array[0..300000] of longint;
    flag:array[0..300000] of char;

begin
  readln(n,m);
  fillchar(a1,sizeof(a1),0);
  fillchar(a2,sizeof(a2),0);
  all:=0;
  for i:=1 to n do
    begin
      read(ch);
      readln(num);
      if ch='+' then inc(a1[num]) else
        begin
          inc(a2[num]);
          inc(all);
        end;
      flag[i]:=ch;
      data[i]:=num;
    end;
  fillchar(ok,sizeof(ok),0);
  sum:=0;
  for i:=1 to n do
    begin
      e1:=a1[i]+(all-a2[i]);
      if e1=m then
        begin
          inc(sum);
          ok[i]:=1;
        end;
    end;
  if sum=1 then
    begin
      for i:=1 to n do
        if ((flag[i]='+') and (ok[data[i]]=1))
        or ((flag[i]='-') and (ok[data[i]]=0)) then
          writeln('Truth')
        else
          writeln('Lie');
    end
  else
    begin
      for i:=1 to n do
        if ok[data[i]]=1 then writeln('Not defined') else
          if flag[i]='+' then writeln('Lie') else
            if flag[i]='-' then writeln('Truth');
    end;
end.