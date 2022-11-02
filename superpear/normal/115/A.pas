var a:array[0..2100,0..2100] of longint;
    n,i,sc:longint;
    depth:array[0..2100] of longint;

procedure search(s:longint);
  var i:longint;
  begin
    depth[s]:=1;
    for i:=1 to a[s,0] do
      if depth[a[s,i]]=0 then
        begin
          search(a[s,i]);
          if depth[a[s,i]]+1>depth[s] then depth[s]:=depth[a[s,i]]+1;
        end;
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(sc);
      if sc=-1 then sc:=0;
      inc(a[sc,0]);
      a[sc,a[sc,0]]:=i;
      inc(a[i,0]);
      a[i,a[i,0]]:=sc;
    end;
  fillchar(depth,sizeof(depth),0);
  search(0);
  writeln(depth[0]-1);
end.