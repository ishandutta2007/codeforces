var n,i,xc,ans:longint;
    a:array[0..100000] of longint;

begin
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    begin
      read(xc);
      inc(a[xc]);
    end;
  ans:=a[4];
  ans:=ans+a[3];
  a[1]:=a[1]-a[3];
  if a[1]<0 then a[1]:=0;
  ans:=ans+(a[2] div 2);
  a[2]:=a[2] mod 2;
  if a[2]=1 then
    begin
      inc(ans);
      dec(a[1],2);
    end;
  if a[1]<0 then a[1]:=0;
  if a[1]>0 then ans:=ans+(a[1]-1) div 4+1;
  writeln(ans);
end.