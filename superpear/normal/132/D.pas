const maxn=1000001;

var st:ansistring;
    sc:string;
    s:array[0..maxn] of char;
    n,i,c:longint;
    f,g,bu,bv:array[0..maxn] of longint;
    u,v:array[0..maxn] of string[15];

begin
  readln(st);
  n:=length(st);
  for i:=1 to n do
    s[i]:=st[n+1-i];
  inc(n);
  s[n]:='0';
  for i:=0 to n do f[i]:=maxlongint div 2;
  for i:=0 to n do g[i]:=maxlongint div 2;
  g[0]:=0;
  for i:=1 to n do
    begin
      str(i-1,sc);
      if s[i]='1' then
        begin
          g[i]:=g[i-1]+1;
          v[i]:='+2^'+sc;
          bv[i]:=1;
          f[i]:=f[i-1];
          u[i]:='';
          bu[i]:=0;
          if g[i-1]<f[i] then
            begin
              f[i]:=g[i-1];
              u[i]:='-2^'+sc;
              bu[i]:=1;
            end;
        end
      else
        begin
          f[i]:=f[i-1]+1;
          u[i]:='-2^'+sc;
          bu[i]:=0;
          g[i]:=g[i-1];
          v[i]:='';
          bv[i]:=1;
          if f[i-1]+2<g[i] then
            begin
              g[i]:=f[i-1]+2;
              v[i]:='+2^'+sc;
              bv[i]:=0;
            end;
        end;
    end;
  writeln(g[n]);
  c:=1;
  for i:=n downto 1 do
    begin
      if c=0 then
        begin
          if u[i]<>'' then writeln(u[i]);
          c:=bu[i];
        end
      else
        begin
          if v[i]<>'' then writeln(v[i]);
          c:=bv[i];
        end;
    end;
end.