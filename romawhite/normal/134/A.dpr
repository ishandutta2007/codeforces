    var a:array[1..200007]of int64;
        s,q:int64;
        i:longint;
        n:longint;
        sol:longint;
        x:array[1..200007]of longint;

    begin
    readln(n);
    for i:=1 to n do read(a[i]);
    s:=0;
    for i:=1 to n do s:=s+a[i];
    for i:=1 to n do
    begin
    q:=-1;
    if (s-a[i]) mod (n-1)=0 then
     q:=(s-a[i]) div (n-1);
     if q=a[i] then begin sol:=sol+1; x[sol]:=i; end;
     end;
      writeln(sol);
      for i:=1 to sol do write(x[i],' ');

      readln;
      readln;

    end.