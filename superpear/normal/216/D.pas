var a,start,c,o1:array[0..300000] of longint;
    n,i,j,k,cs,q,x1,y1,x2,y2,l1,r1,m1,l2,r2,m2,left,right,mid,ans,c1,c2,oo:longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j,x,y:longint;
  begin
    i:=l;
    j:=r;
    x:=a[l+random(r-l+1)];
    repeat
      while a[i]<x do inc(i);
      while x<a[j] do dec(j);
      if i<=j then
        begin
          swap(a[i],a[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  randomize;
  readln(n);
  start[1]:=1;
  for i:=1 to n do
    begin
      read(cs);
      for j:=1 to cs do
        read(a[start[i]+j-1]);
      sort(start[i],start[i]+cs-1);
      start[i+1]:=start[i]+cs;
    end;
  o1[1]:=1;
  for i:=1 to n do
    begin
      q:=o1[i]-1;
      x1:=start[i];x2:=start[i+1]-1;
      y1:=start[i-1];y2:=start[i]-1;
      if i=1 then
        begin
          y1:=start[n];
          y2:=start[n+1]-1;
        end;
      while (x1<=x2) or (y1<=y2) do
        begin
          if (x1<=x2) and (y1<=y2) and (a[x1]=a[y1]) then
            begin
              inc(q);
              c[q]:=a[x1];
              inc(x1);
              inc(y1);
            end
          else
            if (x1>x2) or ((y1<=y2) and (a[x1]>a[y1])) then
              begin
                inc(q);
                c[q]:=a[y1];
                inc(y1);
              end
            else
              begin
                inc(q);
                c[q]:=a[x1];
                inc(x1);
              end;
        end;
      o1[i+1]:=q+1;
    end;
  {for i:=1 to n do
    begin
      for j:=o1[i] to o1[i+1]-1 do write(c[j],' ');
      writeln;
    end; }
  ans:=0;
  for i:=1 to n do
    begin
      for j:=start[i]+1 to start[i+1]-1 do
        begin
          c1:=a[j-1];c2:=a[j];
          //writeln(c1,' ',c2);
          left:=o1[i];
          right:=o1[i+1]-1;
          //for k:=left to right do write(c[k],' ');writeln;
          repeat
            mid:=(left+right) shr 1;
            if c1<=c[mid] then right:=mid-1 else left:=mid+1;
          until left>right;
          l1:=left;
          left:=o1[i];
          right:=o1[i+1]-1;
          repeat
            mid:=(left+right) shr 1;
            if c2>=c[mid] then left:=mid+1 else right:=mid-1;
          until left>right;
          r1:=right;
          m1:=r1-l1+1;
          c1:=a[j-1];c2:=a[j];
          oo:=i+1;
          if oo=n+1 then oo:=1;
          left:=o1[oo];
          right:=o1[oo+1]-1;
          //for k:=left to right do write(c[k],' ');writeln;
          repeat
            mid:=(left+right) shr 1;
            if c1<=c[mid] then right:=mid-1 else left:=mid+1;
          until left>right;
          l2:=left;
          left:=o1[oo];
          right:=o1[oo+1]-1;
          repeat
            mid:=(left+right) shr 1;
            if c2>=c[mid] then left:=mid+1 else right:=mid-1;
          until left>right;
          r2:=right;
          m2:=r2-l2+1;
          if m1<>m2 then inc(ans);
          //writeln(i,' ',j,' ',m1,' ',m2);
        end;
    end;
  writeln(ans);
end.