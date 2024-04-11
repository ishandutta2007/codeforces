var n,m,i,j,k,ans,l,r:longint;
    a,b,c,ll,rr:array[1..500000]of longint;
procedure files(s:string);
  begin
    assign(input,s+'.in');
    reset(input);
    assign(output,s+'.out');
    rewrite(output);
  end;
 procedure sort(l,r: longint);
      var
         i,j,x,y,k: longint;
      begin
         i:=l;
         j:=r;
         k:=random(r-l+1)+l;
         x:=a[k];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
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
     begin
       read(a[i]);
       b[i]:=i;
     end;
    sort(1,n);
    c[b[1]]:=1;
    l:=1;
    for i:=1 to n do
     if a[i]=a[i-1] then c[b[i]]:=l else begin inc(l); c[b[i]]:=l; end;
    a:=c;
    //
    //
    //
    fillchar(c,sizeof(c),0);
    ans:=0;
    k:=1;
    for i:=1 to n do
     if c[a[i]]<>ans+1 then c[a[i]]:=ans+1 else
      begin
        inc(ans);
        ll[ans]:=k;
        rr[ans]:=i;
        k:=i+1;
      end;
    if ans<>0 then rr[ans]:=n;
    if ans=0 then begin writeln('-1'); halt; end;
    writeln(ans);
    for i:=1 to ans do
     writeln(ll[i],' ',rr[i]);

  end.