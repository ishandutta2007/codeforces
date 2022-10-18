var n,m,i,j,k:longint;
    l,r:int64;
    x,y,z:longint;
    a:array[1..100,1..100]of longint;
    b:array[1..100]of longint;
    c:array[1..100]of boolean;
procedure dfs(x:longint);
 var i:longint;
  begin

    c[x]:=true;
    for i:=1 to n do
     if (a[x,i]=1) and (c[i]=false) then dfs(i);
    inc(l);
  end;

  begin
    read(n,m);
    for i:=1 to m do
     begin
       read(l,r);
       inc(a[l,r]);
       inc(a[r,l]);
     end;
    r:=1;
    for i:=1 to n do
     begin
       if not(c[i]) then begin l:=0; dfs(i); for j:=1 to l-1 do
        r:=r*2; end;
     end;
    writeln(r);
  end.