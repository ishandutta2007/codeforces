var p:array[1..200] of longint;
    k,a,b,l,i,j:longint;
    s:string;
function valid(l,k:longint):boolean;
  begin
    if (l<k*a) or (l>k*b) then valid:=false else valid:=true;
  end;
begin
  readln(k,a,b);
  readln(s);
  l:=length(s);
  if (l<k*a) or (l>k*b) then
    begin
      writeln('No solution');halt;
    end;
  for i:=1 to k do
    for j:=a to b do
      if valid(l-j,k-i) then
        begin
          p[i]:=j;dec(l,j);break;
        end;
  l:=0;
  for i:=1 to k do
    begin
      for j:=1 to p[i] do
        begin
          inc(l);write(s[l]);
        end;
      writeln;
    end;
end.