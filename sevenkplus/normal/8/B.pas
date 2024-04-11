program B_;
const l28=1 shl 28;
var a:array[-101..101,-101..101] of boolean;
    d:array[-101..101,-101..101] of longint;
    px,py,pd:array[1..2000] of longint;
    x,y,x1,y1,x2,y2,d1,i,j,f,r,s:longint;
    c:char;
begin
//  assign(input,'B.in');reset(input);
//  assign(output,'B.out');rewrite(output);
  fillchar(a,sizeof(a),false);
  a[0,0]:=true;
  x:=0;y:=0;s:=0;;
  while not eoln do
    begin
      read(c);inc(s);
      if c='L' then dec(x)else
      if c='R' then inc(x)else
      if c='U' then inc(y)else dec(y);
      a[x,y]:=true;
    end;
  for i:=-101 to 101 do
    for j:=-101 to 101 do d[i,j]:=l28;
  d[0,0]:=1;
  f:=1;r:=1;px[1]:=0;py[1]:=0;pd[1]:=0;
  while f<=r do
    begin
      x1:=px[f];y1:=py[f];d1:=pd[f];
      //case 1
      x2:=x1;y2:=y1+1;
      if a[x2,y2] and (d1+1<d[x2,y2]) then
        begin
          d[x2,y2]:=d1+1;inc(r);
          px[r]:=x2;py[r]:=y2;pd[r]:=d1+1;
        end;
      //case 2
      x2:=x1;y2:=y1-1;
      if a[x2,y2] and (d1+1<d[x2,y2]) then
        begin
          d[x2,y2]:=d1+1;inc(r);
          px[r]:=x2;py[r]:=y2;pd[r]:=d1+1;
        end;
      //case 3
      x2:=x1+1;y2:=y1;
      if a[x2,y2] and (d1+1<d[x2,y2]) then
        begin
          d[x2,y2]:=d1+1;inc(r);
          px[r]:=x2;py[r]:=y2;pd[r]:=d1+1;
        end;
      //case 4
      x2:=x1-1;y2:=y1;
      if a[x2,y2] and (d1+1<d[x2,y2]) then
        begin
          d[x2,y2]:=d1+1;inc(r);
          px[r]:=x2;py[r]:=y2;pd[r]:=d1+1;
        end;
      inc(f);
    end;
  if d[x,y]<s then writeln('BUG') else writeln('OK');
//  close(input);close(output);
end.