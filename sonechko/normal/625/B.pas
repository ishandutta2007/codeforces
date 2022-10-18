var s,t:ansistring;
    a,ll,rr:array[1..200000]of longint;
    i,j,k,ans,n,m,l,r:longint;
 begin
   readln(s);
   readln(t);
   s:=t+'*'+s;
   for i:=2 to length(s) do
     begin
       l:=a[i-1];
       while (l>0) do
        begin
          if s[i]=s[l+1] then begin a[i]:=l+1; break; end;
          l:=a[l];
        end;
       if (l=0) and (s[i]=s[1]) then a[i]:=1;
     end;
   for i:=length(t)+2 to length(s) do
    if a[i]=length(t) then
     begin
       n:=n+1;
       rr[n]:=i-length(t)-1;
       ll[n]:=rr[n]-length(t)+1;
     end;
   l:=ll[1];
   r:=rr[1];
   if (n=0) then begin writeln(0); halt; end;
   ans:=1;
   for i:=2 to n do
    if (ll[i]<=r) then l:=ll[i] else
     begin
       ans:=ans+1;
       l:=ll[i];
       r:=rr[i];
     end;
   writeln(ans);
 end.