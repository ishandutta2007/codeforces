program B;
var s:array[1..1000] of ansistring;
    l:array[1..1000] of longint;
    n,i,m,j,d:longint;
    f:boolean;
begin
//  assign(input,'B.in');reset(input);
//  assign(output,'B.out');rewrite(output);
  n:=0;
  while not eof do
    begin
      inc(n);readln(s[n]);l[n]:=length(s[n]);
    end;
  m:=0;
  for i:=1 to n do
    if l[i]>m then m:=l[i];
  for i:=1 to m+2 do write('*');writeln;
  f:=false;
  for i:=1 to n do
    begin
      write('*');
      d:=m-l[i];
      if odd(d) then
        if not f then
          begin
            for j:=1 to d shr 1 do write(' ');
            write(s[i]);
            for j:=1 to d-d shr 1 do write(' ');
            f:=true;
          end else
          begin
            for j:=1 to d-d shr 1 do write(' ');
            write(s[i]);
            for j:=1 to d shr 1 do write(' ');
            f:=false;
          end else
        begin
          for j:=1 to d shr 1 do write(' ');
          write(s[i]);
          for j:=1 to d shr 1 do write(' ');
        end;
      writeln('*');
    end;
  for i:=1 to m+2 do write('*');writeln;
//  close(input);close(output);
end.