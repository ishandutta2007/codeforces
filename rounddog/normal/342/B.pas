
program cf199_2;

var
    i,j,k,l,m,n,r,x,y,f:longint;
    a,b:array[0..200070] of longint;

begin
  readln(n,m,x,y);
  if x<y then f:=1 else f:=-1;
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:= 1 to m do
    begin
      readln(j,l,r);
      if j<200020 then begin
        a[j]:=l; b[j]:=r;
      end;
    end;
  k:=x;
  l:=0;
  if x=y then halt;
  repeat
    inc(l);
    if ((a[l]>k) or (b[l]<k)) and ((a[l]>k+f) or (b[l]<k+f)) then begin
      k:=k+f;
      if f=1 then write('R') else write('L');
    end
    else write('X');
  until k=y;
  writeln;
end.