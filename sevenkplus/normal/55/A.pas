var a:array[1..1000] of boolean;
    i,n,s:longint;
    f:boolean;
begin
  readln(n);s:=1;
  fillchar(a,sizeof(a),false);a[s]:=true;
  for i:=1 to 1000000 do
    begin
      inc(s,i);s:=s mod n;if s=0 then s:=n;a[s]:=true;
    end;
  f:=true;
  for i:=1 to n do f:=f and a[i];
  if f then writeln('YES') else writeln('NO');
end.