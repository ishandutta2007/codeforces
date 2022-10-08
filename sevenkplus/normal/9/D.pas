program D;
var a:array[0..35,0..35] of qword;
    i,j,k,l,n,h:longint;
    s:qword;
begin
//  assign(input,'D.in');reset(input);
//  assign(output,'D.out');rewrite(output);
  readln(n,h);
  fillchar(a,sizeof(a),0);a[1,1]:=1;a[0,0]:=1;
  for i:=2 to n do
    for j:=1 to i do
      for k:=0 to i-1 do
        begin
          for l:=0 to j-1 do inc(a[i,j],a[k,l]*a[i-k-1,j-1]);
          for l:=0 to j-2 do inc(a[i,j],a[i-k-1,l]*a[k,j-1]);
        end;
  s:=0;for i:=h to n do inc(s,a[n,i]);
  writeln(s);
//  close(input);close(output);
end.