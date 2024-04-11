uses math;
var n,i,j,l,mini,s:longint;
    m:array[1..100,1..100]of longint;
    k:array[1..1000]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(k[i]);
    for i:=1 to n do
     begin
       for j:=1 to k[i] do
        read(m[i,j]);
     end;
    mini:=maxlongint;
    for i:=1 to n do
     begin
      s:=0;
      for j:=1 to k[i] do
       s:=s+(m[i,j]*5+15);
      mini:=min(s,mini);
     end;
    writeln(mini);
  end.