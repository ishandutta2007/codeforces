program problem_b;

var
  n,m,ans:longint;
  a:array[1..100]of longint;

procedure init;
  var
    i:longint;
  begin
    readln(n,m);
    for i:=1 to n do read(a[i]);
  end;

procedure sort;
  var
    i,j,t:longint;
  begin
    for i:=1 to n-1 do
      for j:=i+1 to n do
        if a[i]>a[j] then
          begin
            t:=a[i];
            a[i]:=a[j];
            a[j]:=t;
          end;
  end;

procedure work;
  var
    i:longint;
  begin
    ans:=0;
    for i:=1 to m do
      if a[i]<0 then ans:=ans-a[i];
  end;

procedure print;
  begin
    writeln(ans);
  end;

begin
  init;
  sort;
  work;
  print;
end.