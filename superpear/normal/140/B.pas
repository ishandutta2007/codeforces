var a:array[0..1000,0..1000] of longint;
    r,d:array[0..1000] of longint;
    n,i,j,c,max,max2,mk,m2k,e:longint;

begin
  fillchar(a,sizeof(a),0);
  fillchar(r,sizeof(r),0);
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      begin
        read(c);
        a[i,c]:=n+1-j;
      end;
  for i:=1 to n do
    begin
      read(c);
      d[c]:=n+1-i;
    end;
  max:=0;
  max2:=0;
  mk:=0;
  m2k:=0;
  for i:=1 to n do
    begin
      if d[i]>max then
        begin
          max2:=max;
          m2k:=mk;
          max:=d[i];
          mk:=i;
        end
      else
        if d[i]>max2 then
          begin
            max2:=d[i];
            m2k:=i;
          end;
      for j:=1 to n do
        begin
          e:=-1;
          if mk<>j then e:=mk else
            if m2k>0 then e:=m2k;
          if e<>-1 then
            if a[j,e]>a[j,r[j]] then r[j]:=e;
        end;
    end;
  for i:=1 to n-1 do write(r[i],' ');writeln(r[n]);
end.