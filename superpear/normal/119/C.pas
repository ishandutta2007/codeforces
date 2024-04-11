var m,n,key,i,j,k,s,max1,max2:longint;
    a,b:array[0..1000] of int64;
    f:array[0..100,0..100,0..200] of int64;
    p,v:array[0..100,0..100,0..200] of longint;
    c,max:int64;
    q,w:array[0..1000] of longint;

procedure swapi(var a,b:int64);
  var r:int64;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure search(i,j,k:longint);
  begin
    if p[i,j,k]<>-1 then search(p[i,j,k],j-1,v[i,j,k]);
    if p[i,j,k]=-1 then
      writeln(w[i],' ',f[i,j,k])
    else
      writeln(w[i],' ',f[i,j,k]-f[p[i,j,k],j-1,v[i,j,k]]);
  end;

begin
  readln(n,m,key);
  for i:=1 to m do
    begin
      readln(a[i],b[i],q[i]);
      w[i]:=i;
    end;
  for i:=1 to m-1 do
    for j:=i+1 to m do
      if q[i]>q[j] then
        begin
          swapi(a[i],a[j]);
          swapi(b[i],b[j]);
          swap(q[i],q[j]);
          swap(w[i],w[j]);
        end;
  fillchar(f,sizeof(f),0);
  fillchar(p,sizeof(p),0);
  fillchar(v,sizeof(v),0);
  for i:=0 to b[1]-a[1] do
    begin
      f[1,1,i]:=i+a[1];
      p[1,1,i]:=-1;
      v[1,1,i]:=-1;
    end;
  for i:=2 to m do
    begin
      for j:=0 to b[i]-a[i] do
        begin
          f[i,1,j]:=j+a[i];
          p[i,1,j]:=-1;
          v[i,1,j]:=-1;
        end;
      for j:=2 to n do
        for k:=1 to i-1 do
          if q[i]>q[k] then
            for s:=0 to b[k]-a[k] do
              begin
                if p[k,j-1,s]=0 then continue;
                c:=s+a[k]+key;
                if (c>=a[i]) and (c<=b[i]) then
                  if f[k,j-1,s]+c>f[i,j,c-a[i]] then
                    begin
                      f[i,j,c-a[i]]:=f[k,j-1,s]+c;
                      p[i,j,c-a[i]]:=k;
                      v[i,j,c-a[i]]:=s;
                    end;
                c:=(s+a[k])*key;
                if (c>=a[i]) and (c<=b[i]) then
                  if f[k,j-1,s]+c>f[i,j,c-a[i]] then
                    begin
                      f[i,j,c-a[i]]:=f[k,j-1,s]+c;
                      p[i,j,c-a[i]]:=k;
                      v[i,j,c-a[i]]:=s;
                    end;
              end;
    end;
  max1:=0;
  max2:=0;
  max:=0;
  for i:=1 to m do
    for j:=0 to b[i]-a[i] do
      if f[i,n,j]>max then
        begin
          max:=f[i,n,j];
          max1:=i;
          max2:=j;
        end;
  if max=0 then writeln('NO') else
    begin
      writeln('YES');
      search(max1,n,max2);
    end;
end.