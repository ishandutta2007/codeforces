var gb,tt,max,maxk,i,n,sum,x1,y1,r,f,c:longint;
    a:array[0..1000,0..1000] of longint;
    u,ans:array[0..1000] of longint;

begin
  assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);
  readln(tt);
  sum:=0;
  for gb:=1 to tt do
    begin
      fillchar(a,sizeof(a),0);
      read(n);
      for i:=1 to n-1 do
        begin
          read(x1,y1);
          inc(a[x1,0]);
          a[x1,a[x1,0]]:=y1;
          inc(a[y1,0]);
          a[y1,a[y1,0]]:=x1;
        end;
      r:=1;
      f:=1;
      u[r]:=1;
      fillchar(ans,sizeof(ans),0);
      ans[1]:=1;
      while r<=f do
        begin
          for i:=1 to a[u[r],0] do
            begin
              c:=a[u[r],i];
              if ans[c]=0 then
                begin
                  ans[c]:=ans[u[r]]+1;
                  inc(f);
                  u[f]:=c;
                end;
            end;
          inc(r);
        end;
      max:=0;
      maxk:=0;
      for i:=1 to n do
        if ans[i]>max then
          begin
            max:=ans[i];
            maxk:=i;
          end;
      r:=1;
      f:=1;
      u[r]:=maxk;
      fillchar(ans,sizeof(ans),0);
      ans[maxk]:=1;
      while r<=f do
        begin
          for i:=1 to a[u[r],0] do
            begin
              c:=a[u[r],i];
              if ans[c]=0 then
                begin
                  ans[c]:=ans[u[r]]+1;
                  inc(f);
                  u[f]:=c;
                end;
            end;
          inc(r);
        end;
      max:=0;
      for i:=1 to n do
        if ans[i]>max then
          max:=ans[i];
      sum:=sum+max-1;
    end;
  writeln(sum);
  close(input);
  close(output);
end.