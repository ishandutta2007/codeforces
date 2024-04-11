const big=1e+10;

var n,k,m,i,xc,o,j:longint;
    a,use,b:array[0..10000] of longint;
    min,max,s:extended;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  readln(m);
  fillchar(use,sizeof(use),0);
  min:=big;
  max:=0;
  for i:=1 to m do
    begin
      s:=0;
      for j:=1 to (n div k) do
        begin
          read(xc);
          use[xc]:=1;
          s:=s+a[xc];
        end;
      s:=s/(n div k);
      if s>max then max:=s;
      if s<min then min:=s;
    end;
  o:=0;
  for i:=1 to n do
    if use[i]=0 then
      begin
        inc(o);
        b[o]:=a[i];
      end;
  for i:=1 to o-1 do
    for j:=i+1 to o do
      if b[i]>b[j] then swap(b[i],b[j]);
  if (o>=(n div k)) and (o<>n mod k) then
    begin
      s:=0;
      for i:=1 to (n div k) do
        s:=s+b[i];
      s:=s/(n div k);
      if s<min then min:=s;
      s:=0;
      for i:=o-(n div k)+1 to o do
        s:=s+b[i];
      s:=s/(n div k);
      if s>max then max:=s;
    end;
  writeln(min:0:10,' ',max:0:10);
end.