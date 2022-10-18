uses math;
var n,m,k,ans,l,r:int64;
    i,j:longint;
    a,b,next,last,res,cc:array[1..1000000]of int64;
procedure add(l,r:longint);
 begin
   inc(k);
   b[k]:=r;
   next[k]:=last[l];
   last[l]:=k;
 end;
function dfs(v:longint):int64;
 var i:longint;
  begin
    if res[v]<>0 then exit(res[v]);
    i:=last[v];
    while i>0 do
     begin
       res[v]:=max(res[v],dfs(b[i])+1);
       i:=next[i];
     end;
    res[v]:=max(res[v],1);
    exit(res[v]);
  end;
  begin
    read(n,m);
    for i:=1 to m do
     begin
       read(l,r);
       inc(cc[l]);
       inc(cc[r]);
       if l<r then add(r,l) else add(l,r);
     end;
    res[1]:=1;
    for i:=n downto 1 do
     begin
      if res[i]=0 then res[i]:=dfs(i);
      //writeln(i,' ',res[i]);
      ans:=max(ans,res[i]*cc[i]);
     end;
    writeln(ans);
  end.