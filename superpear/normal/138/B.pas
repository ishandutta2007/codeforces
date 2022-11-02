var st:ansistring;
    a,b,c:array[0..10] of longint;
    max,maxk,c1,i,e,j,o:longint;
    x,y:array[0..1000000] of longint;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a) else exit(b);
  end;

begin
  readln(st);
  fillchar(a,sizeof(a),0);
  for i:=1 to length(st) do
    inc(a[ord(st[i])-48]);
  max:=0;
  maxk:=0;
  for i:=1 to 5 do
    begin
      b:=a;
      c:=a;
      dec(b[i]);
      dec(c[10-i]);
      if (b[i]>=0) and (c[10-i]>=0) then
        begin
          e:=1;
          for j:=0 to 9 do
            e:=e+min(b[j],c[9-j]);
          if e>max then
            begin
              max:=e;
              maxk:=i;
            end;
        end;
    end;
  if (max=0) and (a[0]=0) then
    begin
      writeln(st);
      writeln(st);
    end
  else
    if max=0 then
      begin
        for i:=1 to length(st) do if st[i]<>'0' then write(st[i]);
        for i:=1 to a[0] do write('0');writeln;
        for i:=1 to length(st) do if st[i]<>'0' then write(st[i]);
        for i:=1 to a[0] do write('0');writeln;
      end
    else
    begin
      inc(o);
      x[o]:=maxk;
      y[o]:=10-maxk;
      b:=a;
      dec(a[maxk]);
      dec(b[10-maxk]);
      for i:=0 to 9 do
        begin
          c1:=min(a[i],b[9-i]);
          a[i]:=a[i]-c1;
          b[9-i]:=b[9-i]-c1;
          for j:=1 to c1 do
            begin
              inc(o);
              x[o]:=i;
              y[o]:=9-i;
            end;
        end;
      c1:=min(a[0],b[0]);
      a[0]:=a[0]-c1;
      b[0]:=b[0]-c1;
      for i:=0 to 9 do
        for j:=1 to a[i] do
          write(i);
      for i:=o downto 1 do write(x[i]);
      for i:=1 to c1 do write(0);writeln;
      for i:=0 to 9 do
        for j:=1 to b[i] do
          write(i);
      for i:=o downto 1 do write(y[i]);
      for i:=1 to c1 do write(0);writeln;
    end;
end.