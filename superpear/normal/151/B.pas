var n,i,m,j,o1,m1,m2,m3:longint;
    ch,ch1,ch2,ch3,ch4,ch5,ch6:char;
    id:array[0..1000] of string;
    taxi,pizza,girl:array[0..1000] of longint;

begin
  readln(n);
  fillchar(taxi,sizeof(taxi),0);
  fillchar(pizza,sizeof(pizza),0);
  fillchar(girl,sizeof(girl),0);
  for i:=1 to n do
    begin
      read(m);
      read(ch);
      readln(id[i]);
      for j:=1 to m do
        begin
          readln(ch1,ch2,ch3,ch3,ch4,ch5,ch5,ch6);
          if (ch1=ch2) and (ch2=ch3) and (ch3=ch4) and
             (ch4=ch5) and (ch5=ch6) then
               inc(taxi[i])
          else
            if (ch1>ch2) and (ch2>ch3) and (ch3>ch4) and
               (ch4>ch5) and (ch5>ch6) then
                 inc(pizza[i])
               else
                 inc(girl[i]);
        end;
    end;
  m1:=0;
  m2:=0;
  m3:=0;
  for i:=1 to n do
    begin
      if taxi[i]>m1 then m1:=taxi[i];
      if pizza[i]>m2 then m2:=pizza[i];
      if girl[i]>m3 then m3:=girl[i];
    end;
  write('If you want to call a taxi, you should call:');
  o1:=0;
  for i:=1 to n do
    if taxi[i]=m1 then
      begin
        inc(o1);
        if o1>1 then write(',');
        write(' ',id[i]);
      end;
  writeln('.');
  write('If you want to order a pizza, you should call:');
  o1:=0;
  for i:=1 to n do
    if pizza[i]=m2 then
      begin
        inc(o1);
        if o1>1 then write(',');
        write(' ',id[i]);
      end;
  writeln('.');
  write('If you want to go to a cafe with a wonderful girl, you should call:');
  o1:=0;
  for i:=1 to n do
    if girl[i]=m3 then
      begin
        inc(o1);
        if o1>1 then write(',');
        write(' ',id[i]);
      end;
  writeln('.');
end.