var n,m,i,j,k,l,r:longint;
    a,b:array[1..100000]of string;
    s:string;
  begin
    readln(n);
    for i:=1 to n do
     begin
       readln(s);
       a[i]:=copy(s,1,pos(' ',s)-1);
       b[i]:=copy(s,pos(' ',s)+1,length(s));
       if a[i]>b[i] then begin s:=a[i]; a[i]:=b[i]; b[i]:=s; end;
     end;
    s:='';
    for i:=1 to n do
     begin
       read(l);
       if a[l]>s then s:=a[l] else
       if b[l]>s then s:=b[l] else begin writeln('NO'); halt; end;
     end;
    writeln('YES');
  end.