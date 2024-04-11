var n:int64;
    o,i:longint;
    a:array[0..1000000] of int64;

function prime(s:int64):boolean;
  var i:longint;
  begin
    for i:=2 to trunc(sqrt(s)) do
      if s mod i=0 then exit(false);
    exit(true);
  end;

begin
  readln(n);
  o:=0;
  for i:=2 to trunc(sqrt(n)) do
    if n mod i=0 then
      begin
        if prime(i) then
          begin
            inc(o);
            a[o]:=i;
          end;
        if n div i<>i then
          begin
            if prime(n div i) then
              begin
                inc(o);
                a[o]:=n div i;
              end;
          end;
        if o>3 then break;
      end;
  if o=0 then
    begin
      writeln(1);
      writeln(0);
      halt;
    end;
  if n div a[1]<>a[1] then
    if (n mod a[1]=0) and ((n div a[1]) mod a[1]=0) then
      begin
        writeln(1);
        writeln(int64(a[1])*a[1]);
        halt;
      end;
  if (a[2]<>0) and (n div a[1]<>a[2]) then
    begin
      writeln(1);
      writeln(int64(a[1])*a[2]);
      halt;
    end;
  writeln(2);
end.