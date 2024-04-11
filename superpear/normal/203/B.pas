var m,n,i,j,k,s,x1,y1,x,y:longint;
    a:array[0..4000,0..4000] of integer;
begin
  readln(n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
    begin
      readln(x1,y1);
      a[x1,y1]:=1;
      for j:=x1-2 to x1 do
        for k:=y1-2 to y1 do
          if (j>0) and (k>0) then
            begin
              s:=0;
              for x:=j to j+2 do
                for y:=k to k+2 do
                  inc(s,a[x,y]);
              if s=9 then
                begin
                  writeln(i);
                  halt;
                end;
            end;
    end;
  writeln(-1);
end.