var n,m,i,j,k,ans,l,r,ans1,ans2:longint;
    a:array[0..100,0..100]of longint;
    use:array[0..100]of boolean;
procedure dfs(v,sum,k:longint);
 var i:longint;
  begin
    //writeln(v);
    if sum>ans2 then exit;
    if (v=n*2) then
     begin
       if sum<ans1 then begin ans2:=ans1; ans1:=sum; end else
       if sum<ans2 then ans2:=sum;
       exit;
     end;
    use[v]:=false;
    for i:=1 to n*2 do
     if (a[v,i]>0) and (use[i]) and ((k=0) or (abs(v-i)<>n)) then
      begin
        if abs(v-i)=n then dfs(i,sum+a[v,i],1) else dfs(i,sum+a[v,i],k);
      end;
    use[v]:=true;
  end;
  begin
    read(n);
    for i:=1 to n-1 do
     begin
      read(l);
      a[i,i+1]:=l;
      a[i+1,i]:=l;
     end;
    for i:=1 to n-1 do
     begin
       read(l);
       a[n+i,n+i+1]:=l;
       a[n+i+1,n+i]:=l;
     end;
    for i:=1 to n do
     begin
       read(l);
       a[i,i+n]:=l;
       a[i+n,i]:=l;
     end;
    fillchar(use,sizeof(use),true);
    ans1:=maxlongint;
    ans2:=maxlongint;
    dfs(1,0,0);
    writeln(ans1+ans2);
  end.