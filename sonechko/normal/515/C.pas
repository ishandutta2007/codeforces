var n,m,i,j,k,ans,l,r:longint;
    a:array[1..500]of longint;
    s:string;
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
    readln(k);
    readln(s);
    for i:=1 to k do
     if s[i] in ['2','3','5','7'] then begin inc(n); val(s[i],a[n],l); end else
     if s[i]='4' then begin a[n+1]:=3; a[n+2]:=2; a[n+3]:=2; inc(n,3); end else
     if s[i]='6' then begin a[n+1]:=5; a[n+2]:=3; inc(n,2); end else
     if s[i]='8' then begin a[n+1]:=7; a[n+2]:=2; a[n+3]:=2; a[n+4]:=2; inc(n,4); end else
     if s[i]='9' then begin a[n+1]:=7; a[n+2]:=2; a[n+4]:=3; a[n+3]:=3; inc(n,4); end;
    sort(1,n);
    for i:=1 to n do
     write(a[i]);
    writeln;
  end.