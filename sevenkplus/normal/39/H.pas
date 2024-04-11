var n,i,j:longint;
var l:array[1..100] of longint;
t:longint;
procedure pri(k:longint);
  var i:longint;
  begin
    t:=0;
    while k<>0 do
      begin
        inc(t);l[t]:=k mod n;k:=k div n;
      end;
    for i:=t downto 1 do write(l[i]);
  end;
begin
  readln(n);
  for i:=1 to n-1 do
    begin
      for j:=1 to n-1 do
        begin
          pri(i*j);
          if j=n-1 then writeln else write(' ');
        end;
    end;
end.