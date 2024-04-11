var m,n,i,x1,y1,z1,tot,c,e:longint;
    pre,next,pnext:array[0..10000] of longint;

begin
  readln(n,m);
  fillchar(next,sizeof(next),0);
  fillchar(pnext,sizeof(pnext),0);
  fillchar(pre,sizeof(pre),0);
  for i:=1 to m do
    begin
      readln(x1,y1,z1);
      next[x1]:=y1;
      pnext[x1]:=z1;
      pre[y1]:=1;
    end;
  tot:=0;
  for i:=1 to n do
    if (pre[i]=0) and (next[i]<>0) then
      inc(tot);
  writeln(tot);
  for i:=1 to n do
    if (pre[i]=0) and (next[i]<>0) then
      begin
        c:=pnext[i];
        e:=next[i];
        while e<>0 do
          begin
            if next[e]=0 then break;
            if pnext[e]<c then c:=pnext[e];
            e:=next[e];
          end;
        writeln(i,' ',e,' ',c);
      end;
end.