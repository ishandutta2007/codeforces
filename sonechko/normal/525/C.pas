var n,m,j,k,ans,l,r:int64;   i:longint;
    a,b:array[1..100000]of int64;
    use:array[1..100000]of boolean;
 procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]>x do
            inc(i);
           while x>a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    m:=0;
    sort(1,n);
    fillchar(use,sizeof(use),true);
    for i:=1 to (n-1) do
     if use[i] then
      begin
        if a[i]=a[i+1] then begin inc(m); b[m]:=a[i]; use[i+1]:=false; end else
        if a[i]-1=a[i+1] then begin inc(m); b[m]:=a[i+1]; use[i+1]:=false; end;
      end;
    ans:=0;
    for i:=1 to (m-1) do
     if (i mod 2=1) then ans:=ans+(b[i]*b[i+1]);
    writeln(ans);
  end.