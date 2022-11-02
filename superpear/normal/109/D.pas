var a,b,c,use,x,y,bak:array[0..300000] of longint;
    n,i,e,o,luck,flag:longint;

function lucky(s:longint):boolean;
  begin
    while s>0 do
      begin
        if (s mod 10<>4) and (s mod 10<>7) then exit(false);
        s:=s div 10;
      end;
    exit(true);
  end;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j,x,y:longint;
  begin
    i:=l;
    j:=r;
    x:=a[(l+r) div 2];
    repeat
      while a[i]<x do inc(i);
      while x<a[j] do dec(j);
      if i<=j then
        begin
          swap(a[i],a[j]);
          swap(b[i],b[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      bak[i]:=a[i];
      b[i]:=i;
    end;
  flag:=1;
  for i:=2 to n do
    if a[i]<a[i-1] then
      begin
        flag:=0;
        break;
      end;
  if flag=1 then
    begin
      writeln(0);
      halt;
    end;
  sort(1,n);
  //for i:=1 to n do
  //  c[b[i]]:=i;
  for i:=1 to n do
    if lucky(bak[i]) then
      begin
        luck:=i;
        break;
      end;
  o:=0;
  fillchar(use,sizeof(use),0);
  for i:=1 to n do
    if use[i]=0 then
      begin
        use[i]:=1;
        if i=b[i] then continue;
        e:=b[i];
        flag:=0;
        if lucky(bak[i]) then flag:=i;
        while e<>i do
          begin
            if lucky(bak[e]) then flag:=e;
            use[e]:=1;
            e:=b[e];
          end;
        if flag=0 then
          begin
            if luck=0 then
              begin
                writeln(-1);
                halt;
              end;
            inc(o);x[o]:=luck;y[o]:=i;
            e:=i;
            while b[e]<>i do
              begin
                inc(o);
                x[o]:=e;y[o]:=b[e];
                e:=b[e];
              end;
            inc(o);x[o]:=e;y[o]:=luck;
          end
        else
          begin
            e:=flag;
            while b[e]<>flag do
              begin
                inc(o);
                x[o]:=e;y[o]:=b[e];
                if luck=x[o] then luck:=y[o] else
                  if luck=y[o] then luck:=x[o];
                e:=b[e];
              end;
          end;
      end;
  writeln(o);
  for i:=1 to o do
    writeln(x[i],' ',y[i]);
end.