var m,n,k,i,j,sc,last,c:longint;
    data,sum,a:array[0..500,0..500] of longint;
    ch:char;
    ans:int64;

function getsum(x1,y1,x2,y2:longint):longint;
  begin
    exit(sum[x2,y2]-sum[x1-1,y2]-sum[x2,y1-1]+sum[x1-1,y1-1]);
  end;

begin
  readln(m,n,k);
  for i:=1 to m do
    begin
      for j:=1 to n do
        begin
          read(ch);
          data[i,j]:=ord(ch)-48;
        end;
      readln;
    end;
  for i:=1 to m-2 do
    for j:=1 to n-2 do
      begin
        sc:=data[i+1,j]+data[i,j+1]+data[i+1,j+1]+data[i+1,j+2]+data[i+2,j+1];
        if sc=5 then a[i,j]:=1 else a[i,j]:=0;
      end;
  dec(m,2);dec(n,2);
  fillchar(sum,sizeof(sum),0);
  for i:=1 to m do
    for j:=1 to n do
      sum[i,j]:=sum[i,j-1]+sum[i-1,j]-sum[i-1,j-1]+a[i,j];
  ans:=0;
  for i:=1 to m do
    for j:=1 to n do
      begin
        last:=n+1;
        for c:=1 to m do
          begin
            while (last>j) and (getsum(i,j,c,last-1)>=k) do dec(last);
            ans:=ans+int64(n-last+1);
          end;
      end;
  writeln(ans);
end.