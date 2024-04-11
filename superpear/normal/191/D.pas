var m,n,i,x1,y1,ans,xx,yy:longint;
    a:array[0..100000,0..2] of longint;
    use,inp:array[0..100000] of longint;
begin
  readln(n,m);
  fillchar(inp,sizeof(inp),0);
  for i:=1 to m do
    begin
      readln(x1,y1);
      inc(inp[x1]);
      inc(inp[y1]);
      if inp[x1]<=2 then a[x1,inp[x1]]:=y1;
      if inp[y1]<=2 then a[y1,inp[y1]]:=x1;
    end;
  fillchar(use,sizeof(use),0);
  ans:=0;
  for i:=1 to n do
    begin
      if inp[i]<>2 then use[i]:=1;
      if inp[i] and 1=1 then inc(ans);
    end;
  ans:=ans shr 1;
  for i:=1 to n do
    if use[i]=0 then
      begin
        use[i]:=1;
        xx:=i;
        x1:=a[i,1];
        while use[x1]=0 do
          begin
            use[x1]:=1;
            if a[x1,2]=xx then
              begin
                xx:=x1;
                x1:=a[x1,1];
              end
            else
              begin
                xx:=x1;
                x1:=a[x1,2];
              end;
          end;
        if x1=i then
          begin
            inc(ans);
            continue;
          end;
        yy:=i;
        y1:=a[i,2];
        while use[y1]=0 do
          begin
            use[y1]:=1;
            if a[y1,2]=yy then
              begin
                yy:=y1;
                y1:=a[y1,1];
              end
            else
              begin
                yy:=y1;
                y1:=a[y1,2];
              end;
          end;
        if x1=y1 then inc(ans);
      end;
  writeln(ans,' ',m);
end.