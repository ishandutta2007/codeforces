var m,n,i,j,c,d,u,ss,cc,k,e,q,flag,ans:longint;
    f:array[0..40,0..10000] of longint;
    a,b:array[0..40] of longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin
  readln(m,n);
  if m<n then swap(m,n);
  if n=1 then
    begin
      writeln(m-(m-1) div 3-1);
      halt;
    end;
  filldword(f,sizeof(f) div 4,maxlongint);
  c:=1 shl (n*2)-1;
  d:=1 shl n-1;
  for i:=0 to d do
    begin
      ss:=0;
      e:=i;
      while e>0 do
        begin
          inc(ss,e mod 2);
          e:=e div 2;
        end;
      q:=i;
      for j:=1 to n do q:=q*2;
      f[1,q]:=ss;
    end;
  for i:=1 to m-1 do
    for j:=0 to c do
      if f[i,j]<>maxlongint then
        begin
          //writeln(i,' ',j,' ',f[i,j]);
          k:=n*2;
          e:=j;
          fillchar(a,sizeof(a),0);
          while e>0 do
            begin
              a[k]:=e mod 2;
              e:=e div 2;
              k:=k-1;
            end;
          for k:=0 to d do
            begin
              u:=n;
              e:=k;
              fillchar(b,sizeof(b),0);
              ss:=0;
              while e>0 do
                begin
                  b[u]:=e mod 2;
                  e:=e div 2;
                  inc(ss,b[u]);
                  dec(u);
                end;
              flag:=1;
              for cc:=1 to n do
                begin
                  if (a[cc]=1) or (b[cc]=1) or (a[cc+n]=1) or
                  ((cc<>1) and (a[cc-1]=1)) or ((cc<>n) and (a[cc+1]=1)) then
                    continue;
                  flag:=0;
                  break;
                end;
              if flag=1 then
                begin
                  //for cc:=1 to n do write(b[cc]);writeln;
                  q:=0;
                  for cc:=1 to n do q:=q*2+b[cc];
                  for cc:=1 to n do q:=q*2+a[cc];
                  if f[i,j]+ss<f[i+1,q] then f[i+1,q]:=f[i,j]+ss;
                end;
            end;
        end;
  ans:=maxlongint;
  for i:=0 to c do
    if f[m,i]<ans then
      begin
        k:=n*2;
        e:=i;
        fillchar(a,sizeof(a),0);
        while e>0 do
          begin
            a[k]:=e mod 2;
            e:=e div 2;
            k:=k-1;
          end;
        //for j:=1 to n*2 do write(a[i]);writeln;
        flag:=1;
        for j:=1 to n do
          begin
            if (a[j]=1) or (a[j+n]=1) or
            ((j<>1) and (a[j-1]=1)) or ((j<>n) and (a[j+1]=1)) then
              continue;
            flag:=0;
            break;
          end;
        if flag=1 then
          ans:=f[m,i];
    end;
  writeln(m*n-ans);
end.