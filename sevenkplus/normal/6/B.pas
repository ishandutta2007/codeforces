program B;
var a:array[0..101,0..101] of char;
    c:array[0..101,0..101] of boolean;
    p:array[char] of boolean;
    n,m,i,j,x,y,s:longint;
    d,ch:char;
procedure fi(x,y:longint);
  begin
    c[x,y]:=true;
    if (a[x,y-1]=d) and not c[x,y-1] then fi(x,y-1);
    if (a[x,y+1]=d) and not c[x,y+1] then fi(x,y+1);
    if (a[x-1,y]=d) and not c[x-1,y] then fi(x-1,y);
    if (a[x+1,y]=d) and not c[x+1,y] then fi(x+1,y);
  end;
begin
//  assign(input,'B.in');reset(input);
//  assign(output,'B.out');rewrite(output);
  read(n,m);
  while not eoln do read(d);readln;
  fillchar(c,sizeof(c),false);
  for i:=0 to 101 do
    begin
      c[i,0]:=true;c[0,i]:=true;a[i,0]:='.';a[0,i]:='.';
    end;
  for i:=1 to n do
    begin
      for j:=1 to m do read(a[i,j]);
      readln;
    end;
  for x:=1 to n do
    begin
      for y:=1 to m do
        if a[x,y]=d then break;
      if a[x,y]=d then break;
    end;
  fi(x,y);
  fillchar(p,sizeof(p),false);
  for i:=1 to n do
    for j:=1 to m do
      if c[i,j] then
        begin
          p[a[i,j+1]]:=true;
          p[a[i,j-1]]:=true;
          p[a[i-1,j]]:=true;
          p[a[i+1,j]]:=true;
        end;
  s:=0;
  for ch:='A' to 'Z' do
    if p[ch] and (ch<>d) then inc(s);
  writeln(s);
//  close(input);close(output);
end.