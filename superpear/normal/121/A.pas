var i,j,o,l,r,last:longint;
    b:array[0..10] of longint;
    a:array[0..100000] of int64;
    s,ans:int64;

begin
  o:=0;
  for i:=1 to 10 do
    begin
      fillchar(b,sizeof(b),0);
      while b[0]=0 do
        begin
          s:=0;
          for j:=1 to i do
            if b[j]=0 then s:=int64(s)*10+4 else s:=int64(s)*10+7;
          inc(o);
          a[o]:=s;
          j:=i;
          while b[j]=1 do
            begin
              b[j]:=0;
              dec(j);
            end;
          inc(b[j]);
        end;
    end;
  //for i:=1 to o do writeln(a[i]);
  readln(l,r);
  ans:=0;
  last:=l;
  for i:=1 to o do
    if a[i]>=last then
      begin
        if a[i]<=r then
          begin
            ans:=ans+int64(a[i]-last+1)*a[i];
            last:=a[i]+1;
          end
        else
          begin
            ans:=ans+int64(r-last+1)*a[i];
            break;
          end;
      end;
  writeln(ans);
end.