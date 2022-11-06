program problem_a;

var
  n,ans_x,ans_y:longint;
  a:array[1..100]of longint;

procedure init;
  var
    i:longint;
  begin
    readln(n);
    for i:=1 to n do read(a[i]);
  end;

procedure work;
  var
    i,d,min:longint;
  begin
    min:=maxlongint;
    for i:=1 to n do
      begin
        d:=abs(a[i]-a[i mod n+1]);
        if d<min then
          begin
            min:=d;
            ans_x:=i;
            ans_y:=i mod n+1;
          end;
      end;
  end;

procedure print;
  begin
    writeln(ans_x,' ',ans_y);
  end;

begin
  init;
  work;
  print;
end.