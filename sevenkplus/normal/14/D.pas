var he:array[1..100000] of longint;
    ne,ad,f1,f2,f:array[-100000..100000] of longint;
    v:array[-100000..100000] of boolean;
    n,i,x,y:longint;
    s:int64;
procedure ff(x:longint);
  var p:longint;
  begin
    if v[x] then exit;v[x]:=true;
    p:=he[ad[x]];
    while p<>0 do
      begin
        if x<>-p then
          begin
            ff(p);
            if f[p]>f[x] then f[x]:=f[p];
            if f1[p]>=f1[x] then
              begin
                f2[x]:=f1[x];f1[x]:=f1[p]+1;
              end else
            if f1[p]>=f2[x] then f2[x]:=f1[p]+1;
          end;
        p:=ne[p];
      end;
    if f1[x]+f2[x]>f[x] then f[x]:=f1[x]+f2[x];
  end;
begin
  readln(n);
  fillchar(he,sizeof(he),0);
  for i:=1 to n-1 do
    begin
      readln(x,y);
      ne[ i]:=he[x];he[x]:= i;ad[ i]:=y;
      ne[-i]:=he[y];he[y]:=-i;ad[-i]:=x;
    end;
  s:=0;
  fillchar(v,sizeof(v),false);
  fillchar(f1,sizeof(f1),0);
  fillchar(f2,sizeof(f2),0);
  fillchar(f,sizeof(f),0);
  for i:=1 to n-1 do
    begin
      ff(i);ff(-i);
      if int64(f[i])*f[-i]>s then s:=int64(f[i])*f[-i];
    end;
  writeln(s);
end.