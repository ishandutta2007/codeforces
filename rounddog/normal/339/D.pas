
program cf_4;

type tree=record
  l,r,f:longint;
  s,d:longint;
end;

var
    a:array[1..524288] of tree;
    i,j,k,l,m,n,v,u,max,p:longint;
    fp:boolean;

begin
  fillchar(a,sizeof(a),0);
  readln(n,m);
  l:=n;
  max:=1;
  for i:= 1 to n do
    max:=max*2;
  for i:= 1 to max do
    begin
      read(a[i].s);
      a[i].d:=1;
    end;
  readln;
  k:=max;
  u:=max;
  j:=0;
  fp:=false;
  repeat
    u:=u div 2;
    v:=k;
    repeat
      inc(k);
      with a[k] do
        begin
          l:=j+1;
          r:=j+2;
          d:=a[j+1].d+1;
          if fp then s:=a[j+1].s xor a[j+2].s
          else s:=a[j+1].s or a[j+2].s;
        end;
      a[j+1].f:=k;
      a[j+2].f:=k;
      j:=j+2;
    until k=u+v;
    fp:=not(fp);
  until u=1;
  for i:= 1 to m do
    begin
      readln(u,v);
      a[u].s:=v;
      p:=a[u].f;
      repeat
        if a[p].d mod 2=1 then a[p].s:=a[a[p].l].s xor a[a[p].r].s
        else a[p].s:=a[a[p].l].s or a[a[p].r].s;
        p:=a[p].f;
      until p=0;
      writeln(a[max*2-1].s);
    end;
end.