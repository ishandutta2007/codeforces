var n,m,i,j,k,ans,l,r:longint;
    a,b,c,d,e,f:array[0..100000]of int64;
    ch,h:char;
 procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
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
  procedure sort1(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=c[(l+r) div 2];
         repeat
           while c[i]>x do
            inc(i);
           while x>c[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=c[i];
                c[i]:=c[j];
                c[j]:=y;
                y:=d[i];
                d[i]:=d[j];
                d[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort1(l,j);
         if i<r then
           sort1(i,r);
      end;
  begin
    readln(n,m);
    for i:=1 to n do
     begin
       read(ch,h);
       if ch='S' then begin inc(l); readln(a[l],h,b[l]); end else
       begin inc(r); readln(c[r],h,d[r]); end;
     end;
    sort(1,l);
    sort1(1,r);
    if l=0 then k:=0 else k:=1;
    e[k]:=a[1];
    f[k]:=b[1];
    for i:=2 to l do
     begin
       //writeln(k,' ',e[k],' ',f[k],' ',i,' ',a[i],' ',b[i]);
      if a[i]=e[k] then f[k]:=f[k]+b[i] else
     if k=m then break else begin inc(k); e[k]:=a[i]; f[k]:=b[i]; end;
      end;
    for i:=k downto 1 do
     writeln('S ',e[i],' ',f[i]);
    a:=c;
    b:=d;
    if r=0 then k:=0 else k:=1;
    e[k]:=a[1];
    f[k]:=b[1];
    for i:=2 to r do
     if a[i]=e[k] then f[k]:=f[k]+b[i] else
     if k=m then break else begin inc(k); e[k]:=a[i]; f[k]:=b[i]; end;
    for i:=1 to k do
     writeln('B ',e[i],' ',f[i]);

  end.