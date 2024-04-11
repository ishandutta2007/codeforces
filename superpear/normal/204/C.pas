var ans:extended;
    ch1,ch2:array[0..200010] of char;
    a,b:array[0..200010] of longint;
    sum:array[0..200010] of int64;
    n,i,o1,o2,e1:longint;
    ic:char;
    fm:int64;
begin
  //assign(input,'E.in');
  //reset(input);

  readln(n);
  for i:=1 to n do
    read(ch1[i]);
  readln;
  for i:=1 to n do
    read(ch2[i]);
  fm:=0;
  for i:=1 to n do
    fm:=fm+int64(n-i+1)*(n-i+1);
  ans:=0;
  for ic:='A' to 'Z' do
    begin
      o1:=0;
      for i:=1 to n do
        if ch1[i]=ic then
          begin
            inc(o1);
            a[o1]:=i;
          end;
      o2:=0;
      for i:=1 to n do
        if ch2[i]=ic then
          begin
            inc(o2);
            b[o2]:=i;
          end;
      sum[0]:=0;
      for i:=1 to o2 do
        sum[i]:=sum[i-1]+b[i];
      e1:=0;
      for i:=1 to o1 do
        begin
          while (e1<o2) and (b[e1+1]<=a[i]) do inc(e1);
          ans:=ans+(n-a[i]+1)*sum[e1]+a[i]*(int64(n+1)*(o2-e1)-(sum[o2]-sum[e1]))
        end;
    end;
  writeln(ans/fm:0:10);

  close(input);
end.