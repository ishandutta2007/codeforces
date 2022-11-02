var x1,y1,z1,i,n:longint;
    ans:int64;
    s,fa:array[0..100000] of longint;

function lucky(s:longint):boolean;
  begin
    while s>0 do
      begin
        if (s mod 10<>4) and (s mod 10<>7) then exit(false);
        s:=s div 10;
      end;
    exit(true);
  end;

function mark(s:longint):longint;
  var c,d,e:longint;
  begin
    c:=s;
    while fa[c]<>c do c:=fa[c];
    d:=s;
    while fa[d]<>d do
      begin
        e:=fa[d];
        fa[d]:=c;
        d:=e;
      end;
    exit(c);
  end;

begin
  readln(n);
  for i:=1 to n do fa[i]:=i;
  for i:=1 to n-1 do
    begin
      readln(x1,y1,z1);
      if not lucky(z1) then fa[mark(x1)]:=mark(y1);

    end;
  fillchar(s,sizeof(s),0);
  for i:=1 to n do inc(s[mark(i)]);
  ans:=0;
  for i:=1 to n do
    ans:=ans+int64(s[i])*(n-s[i])*(n-s[i]-1);
  writeln(ans);

end.