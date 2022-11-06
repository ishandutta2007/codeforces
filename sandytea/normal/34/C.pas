program problem_c;

var
  ans:longint;
  flag:array[0..1001]of boolean;
  x,y:array[0..1001]of longint;

procedure init;
  var
    x:longint;
    c:char;
  begin
    fillchar(flag,sizeof(flag),false);
    x:=0;
    while not eoln do
      begin
        read(c);
        if c<>',' then x:=x*10+ord(c)-48
                  else
                    begin
                      flag[x]:=true;
                      x:=0;
                    end;
      end;
    flag[x]:=true;
  end;

procedure work;
  var
    p:longint;
  begin
    p:=0;ans:=0;
    while p<1001 do
      begin
        while(not flag[p])and(p<1001)do inc(p);
        if flag[p] then
          begin
            inc(ans);x[ans]:=p;
            repeat
              inc(p);
            until not flag[p];
            y[ans]:=p-1;
          end;
      end;
  end;

procedure print;
  var
    i:longint;
  procedure print(i:longint);
    begin
      if x[i]=y[i] then write(x[i])
                   else write(x[i],'-',y[i]);
    end;
  begin
    for i:=1 to ans-1 do
      begin
        print(i);
        write(',');
      end;
    print(ans);
    writeln;
  end;

begin
  init;
  work;
  print;
end.