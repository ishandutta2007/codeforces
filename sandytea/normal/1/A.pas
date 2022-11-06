program problem_a;

var
  n,m,a:longint;
  ans:int64;

procedure init;
  begin
    readln(n,m,a);
  end;

procedure work;
  var
    x,y:longint;
  begin
    x:=(n-1)div a+1;
    y:=(m-1)div a+1;
    ans:=int64(x)*y;
  end;

procedure print;
  begin
    writeln(ans);
  end;

begin
  init;
  work;
  print;
end.