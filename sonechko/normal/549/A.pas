var n,m,i,j,k,ans,l,r:longint;
    a:array[0..50,0..50]of char;
    b:array['a'..'z']of longint;
  begin
    readln(n,m);
    for i:=1 to n do
     begin
       for j:=1 to m do
        read(a[i,j]);
       readln;
     end;
    for i:=1 to n-1 do
     for j:=1 to m-1 do
      begin
        b[a[i,j]]:=1;
        b[a[i,j+1]]:=1;
        b[a[i+1,j]]:=1;
        b[a[i+1,j+1]]:=1;
        if (b['f']=1) and (b['a']=1) and (b['c']=1) and (b['e']=1)
         then inc(ans);
        b[a[i,j]]:=0;
        b[a[i,j+1]]:=0;
        b[a[i+1,j]]:=0;
        b[a[i+1,j+1]]:=0;
      end;
    writeln(ans);
  end.