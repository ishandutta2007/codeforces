var m,n,i,j,x,y,l,x1,y1,flag1,flag2:longint;
    data,c:array[0..40,0..40] of char;
    sg:array[0..21,0..21,0..21,0..21] of longint;

function search(x1,y1,x2,y2:longint):longint;
  var hash:array[0..400] of shortint;
      i,j,s1:longint;
  begin
    if x1>x2 then exit(0);
    if y1>y2 then exit(0);
    if sg[x1,y1,x2,y2]<>-1 then exit(sg[x1,y1,x2,y2]);
    fillchar(hash,sizeof(hash),0);
    for i:=x1 to x2 do
      for j:=y1 to y2 do
        begin
          if c[i,j]=' ' then continue;
          if c[i,j]='L' then
            begin
              s1:=search(x1,y1,x2,j-1) xor search(x1,j+1,x2,y2);
              hash[s1]:=1;
            end;
          if c[i,j]='R' then
            begin
              s1:=search(x1,y1,i-1,y2) xor search(i+1,y1,x2,y2);
              hash[s1]:=1;
            end;
          if c[i,j]='X' then
            begin
              s1:=search(x1,y1,i-1,j-1) xor search(x1,j+1,i-1,y2) xor
                  search(i+1,y1,x2,j-1) xor search(i+1,j+1,x2,y2);
              hash[s1]:=1;
            end;
        end;
    for i:=0 to 400 do
      if hash[i]=0 then
        begin
          sg[x1,y1,x2,y2]:=i;
          break;
        end;
    exit(sg[x1,y1,x2,y2]);
  end;

begin
  readln(m,n);
  for i:=1 to m do
    begin
      for j:=1 to n do
        read(data[i,j]);
      readln;
    end;
  if m>n then l:=m else l:=n;
  for i:=1 to l do
    for j:=1 to l do
      c[i,j]:=' ';
  for i:=n downto 1 do
    if (i+1) mod 2=0 then
      begin
        x:=(n-i) div 2+1;
        y:=(n+1) div 2+1-x;
        x1:=1;
        y1:=i;
        while (x1<=m) and (y1<=n) do
          begin
            c[x,y]:=data[x1,y1];
            inc(y);
            inc(x1);
            inc(y1);
          end;
      end;
  for i:=2 to m do
    if (i+1) mod 2=0 then
      begin
        x:=(n+1) div 2+(i div 2);
        y:=(i+1) div 2;
        x1:=i;
        y1:=1;
        while (x1<=m) and (y1<=n) do
          begin
            c[x,y]:=data[x1,y1];
            inc(y);
            inc(x1);
            inc(y1);
          end;
      end;    {
  for i:=1 to l do
    begin
      for j:=1 to l do
        write(c[i,j]);
      writeln;
    end;       }
  fillchar(sg,sizeof(sg),255);
  flag1:=search(1,1,l,l);
  for i:=1 to l do
    for j:=1 to l do
      c[i,j]:=' ';
  for i:=n downto 1 do
    if (i+1) mod 2=1 then
      begin
        x:=(n-i) div 2+1;
        y:=n div 2+1-x;
        x1:=1;
        y1:=i;
        while (x1<=m) and (y1<=n) do
          begin
            c[x,y]:=data[x1,y1];
            inc(y);
            inc(x1);
            inc(y1);
          end;
      end;
  for i:=2 to m do
    if (i+1) mod 2=1 then
      begin
        x:=n div 2+(i div 2);
        y:=i div 2;
        x1:=i;
        y1:=1;
        while (x1<=m) and (y1<=n) do
          begin
            c[x,y]:=data[x1,y1];
            inc(y);
            inc(x1);
            inc(y1);
          end;
      end;
  {for i:=1 to l do
    begin
      for j:=1 to l do
        write(c[i,j]);
      writeln;
    end;}
  fillchar(sg,sizeof(sg),255);
  flag2:=search(1,1,l,l);
  if flag1=flag2 then writeln('LOSE') else writeln('WIN');
end.