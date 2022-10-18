var n,m,k,r:int64;   i,j:longint;
    l:int64;
    a:array[1..26]of int64;
    s:ansistring;
    h:char;
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
    readln(n,m);
    readln(s);
    for i:=1 to n do
     inc(a[ord(s[i])-64]);
    sort(1,26);
    l:=0;
    for i:=1 to 26 do
     begin
       if a[i]<=m then begin l:=l+a[i]*a[i]; m:=m-a[i]; end else
                       begin l:=l+m*m; break; end;
       if m=0 then break;
     end;
    writeln(l);
  end.