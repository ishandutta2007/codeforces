type rec=record
  f:longint;
  b:array[1..100]of longint;
end;
var n,m,i,j,k,l,r,ans:longint;
    a:array[1..100,1..100]of rec;
    use:array[1..100]of boolean;
procedure dfs(x,y:longint);
 var i:longint;
  begin
    use[x]:=true;
    for i:=1 to n do
     if (a[x,i].b[y]=1) and (use[i]=false) then dfs(i,y);
  end;
  begin
    read(n,m);
    for i:=1 to m do
     begin
       read(l,r,k);
       inc(a[l,r].f);
       a[l,r].b[k]:=1;
       inc(a[r,l].f);
       a[r,l].b[k]:=1;
     end;
    read(k);
    for i:=1 to k do
     begin
       read(l,r);
       ans:=0;
       for j:=1 to m do
        begin
          fillchar(use,sizeof(use),false);
          dfs(l,j);
          if use[r] then inc(ans);
        end;
       writeln(ans);
     end;
  end.