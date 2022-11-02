var m,n,e,max,q,i,j,x,y,z,s,flag:longint;
    f:array[0..2000,0..2000] of longint;
    v:array[0..20,0..2000] of longint;
    b:array[0..20] of longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin
  readln(m,n);
  e:=m*((n-1) div 3+1);
  if (n>1) and (n mod 3<>1) and (m<=2) then e:=e+m;
  max:=e;
  e:=n*((m-1) div 3+1);
  if (m>1) and (m mod 3<>1) and (n<=2) then e:=e+n;
  if e>max then max:=e;
  if (m*n+1) div 2>max then max:=(m*n+1) div 2;
  if (n=2) and (m>3) then swap(m,n);
  if (m=2) and (n>4) then
    if 4*((n-4) div 5)+6>max then max:=4*((n-4) div 5)+6;
  if m<n then swap(m,n);
  if n<=4 then
    begin
      for i:=0 to 2000 do
        for j:=0 to 2000 do
          f[i,j]:=-1;
      f[0,0]:=0;
      for i:=0 to m-1 do
        for j:=0 to (1 shl (n*2)-1) do
          if f[i,j]<>-1 then
            begin
              q:=j;
              for x:=1 to 2 do
                for y:=n downto 1 do
                  begin
                    v[x,y]:=q mod 2;
                    q:=q div 2;
                  end;
              fillchar(b,sizeof(b),0);
              while b[0]=0 do
                begin
                  s:=n;
                  while b[s]=1 do
                    begin
                      b[s]:=0;
                      dec(s);
                    end;
                  inc(b[s]);
                  flag:=1;
                  for z:=1 to n do
                    begin
                      for x:=1 to 2 do
                        begin
                          for y:=1 to n do
                            if (b[z]=1) and (v[x,y]=1) and (x*x+(y-z)*(y-z)=5) then
                              begin
                                flag:=0;
                                break;
                              end;
                          if flag=0 then break;
                        end;
                      if flag=0 then break;
                    end;
                  if flag=1 then
                    begin
                      s:=0;
                      for z:=1 to n do s:=s+b[z];
                      q:=0;
                      for z:=1 to n do q:=q*2+v[1,z];
                      for z:=1 to n do q:=q*2+b[z];
                      if f[i,j]+s>f[i+1,q] then
                        f[i+1,q]:=f[i,j]+s;
                      if (i+1=m) and (f[i+1,q]>max) then
                        max:=f[i+1,q];
                    end;
                end;
            end;
    end;
  writeln(max);
end.