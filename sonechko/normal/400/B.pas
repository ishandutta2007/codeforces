var n,m,k,p,o:int64;
    l,i,j:longint;
    a:array[1..1001,1..1001]of char;
    b:array[1..1001]of longint;


procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=b[(l+r) div 2];
         repeat
           while b[i]<x do
            inc(i);
           while x<b[j] do
            dec(j);
           if not(i>j) then
             begin
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
    readln(n,m);
    for i:=1 to n do
     begin
     for j:=1 to m do
      read(a[i,j]);
     readln;
     end;

    for i:=1 to n do
     begin
      k:=0;
      p:=0;
      for j:=1 to m do
       if (a[i,j]='G') then k:=j else
       if (a[i,j]='S') then p:=j;
      b[i]:=p-k+1;
     end;
    sort(1,n);
    k:=0;
    for i:=1 to n do
     if b[i]<=0 then begin writeln('-1'); halt; end
                else
     if b[i]<>b[i+1] then inc(k);
    writeln(k);
  end.