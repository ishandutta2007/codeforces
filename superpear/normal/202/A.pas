var s,st1,st2,max:string;
    n,i,j:longint;
    b:array[0..1000] of longint;
begin
  readln(s);
  n:=length(s);
  fillchar(b,sizeof(b),0);
  while b[0]=0 do
    begin
      j:=n;
      while b[j]=1 do
        begin
          b[j]:=0;
          dec(j);
        end;
      inc(b[j]);
      st1:='';
      st2:='';
      for i:=1 to n do
        if b[i]=1 then
          begin
            st1:=st1+s[i];
            st2:=s[i]+st2;
          end;
      if st1=st2 then
        if st1>max then max:=st1;
    end;
  writeln(max);
end.