var m,n,a1,b1,mink,i,j,xc,tot,i1,j1,k,x1,y1:longint;
    e:extended;
    p:array[0..40] of extended;
    biao:array[0..40,0..40] of longint;
    a:array[0..40,0..40] of extended;
    f:array[0..300,0..300] of extended;
    ans,lou:array[0..300] of extended;
    inp:array[0..40] of longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure swapr(var a,b:extended);
  var r:extended;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin
  readln(n,m,a1,b1);
  if a1<b1 then swap(a1,b1);
  for i:=0 to n do
    for j:=0 to n do
      a[i,j]:=0;
  for i:=1 to m do
    begin
      readln(x1,y1);
      a[x1,y1]:=1;
      a[y1,x1]:=1;
      inc(inp[x1]);
      inc(inp[y1]);
    end;
  for i:=1 to n do readln(p[i]);
  for i:=1 to n do
    for j:=1 to n do
      if i=j then a[i,j]:=p[i] else a[i,j]:=a[i,j]*(1-p[i])/inp[i];
  tot:=0;
  for i:=1 to n do
    for j:=1 to i do
      begin
        inc(tot);
        biao[i,j]:=tot;
        biao[j,i]:=tot;
      end;
  if a1=b1 then
    begin
      for i:=1 to n-1 do
        if i=a1 then write('1 ') else write('0 ');
      if n=a1 then writeln(1) else writeln(0);
      halt;
    end;
  for xc:=1 to n do
    begin
      if xc>1 then write(' ');
      for i:=0 to tot do
        for j:=0 to tot do
          f[i,j]:=0;
      for i:=0 to tot do
        ans[i]:=0;
      for i:=1 to n do
        for j:=1 to i-1 do
          begin
            f[biao[i,j],biao[i,j]]:=-1;
            ans[biao[i,j]]:=0;
            for i1:=1 to n do
              for j1:=1 to n do
                if (i1<>j1) or ((i1=j1) and (i1=xc)) then
                  f[biao[i,j],biao[i1,j1]]:=f[biao[i,j],biao[i1,j1]]+a[i,i1]*a[j,j1];
          end;
      f[biao[xc,xc],biao[xc,xc]]:=1;
      ans[biao[xc,xc]]:=1;
      for i:=1 to tot do
        begin
          mink:=0;
          for j:=i to tot do
            if f[j,i]<>0 then
              begin
                mink:=j;
                break;
              end;
          for j:=1 to tot do swapr(f[i,j],f[mink,j]);
          swapr(ans[i],ans[mink]);
          for j:=i+1 to tot do
            if f[j,i]<>0 then
              begin
                e:=f[j,i]/f[i,i];
                for k:=i to tot do
                  f[j,k]:=f[j,k]-e*f[i,k];
                ans[j]:=ans[j]-e*ans[i];
              end;
        end;
      for i:=tot downto 1 do
        begin
          for j:=i+1 to tot do ans[i]:=ans[i]-f[i,j]*lou[j];
          if f[i,i]<>0 then lou[i]:=ans[i]/f[i,i];
        end;
      write(lou[biao[a1,b1]]:0:10);
    end;
  writeln;
end.