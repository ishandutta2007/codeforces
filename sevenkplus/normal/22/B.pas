var a:array[1..25,1..25] of boolean;
    b:array[1..25,0..25] of longint;
    n,m,i,j,k,l,s:longint;
    c:char;
begin
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(c);
          a[i,j]:=c='0';
        end;
      readln;
    end;
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
    for j:=1 to m do
      if not a[i,j] then b[i,j]:=0 else b[i,j]:=b[i,j-1]+1;
  s:=0;
  for i:=1 to n do
    for j:=1 to m do
      begin
        l:=20000;
        for k:=i to n do
          begin
            if l>b[k,j] then l:=b[k,j];
            if l=0 then break;
            if l*2+(k-i+1)*2>s then s:=l*2+(k-i+1)*2;
          end;
      end;
  writeln(s);
end.