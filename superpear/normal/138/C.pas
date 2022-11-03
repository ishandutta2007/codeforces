type tree=^pear;
     pear=record
            num,delta:extended;
            left,right:longint;
            lchild,rchild:tree;
            flag:boolean;
          end;

var root:tree;
    a,h,l,r,b,z:array[0..1000000] of longint;
    m,n,i,left,right,l1,r1,mid,c:longint;
    sum:extended;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j,c:longint;
  begin
    i:=l;
    j:=r;
    c:=b[l+random(r-l+1)];
    repeat
      while b[i]<c do inc(i);
      while c<b[j] do dec(j);
      if i<=j then
        begin
          swap(b[i],b[j]);
          swap(z[i],z[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure maketree(l,r:longint;var node:tree);
  var p:tree;
  begin
    new(p);
    p^.delta:=1;
    p^.num:=1;
    p^.flag:=false;
    p^.left:=l;
    p^.right:=r;
    p^.lchild:=nil;
    p^.rchild:=nil;
    node:=p;
    if l=r then
      exit
    else
      begin
        maketree(l,(l+r) div 2,node^.lchild);
        maketree((l+r) div 2+1,r,node^.rchild);
      end;
  end;

procedure downit(p:tree);
  begin
    if p^.flag then
      begin
        if p^.lchild<>nil then
          begin
            p^.lchild^.delta:=p^.lchild^.delta*p^.delta;
            p^.lchild^.num:=p^.lchild^.num*p^.delta;
            p^.rchild^.delta:=p^.rchild^.delta*p^.delta;
            p^.rchild^.num:=p^.rchild^.num*p^.delta;
            p^.lchild^.flag:=true;
            p^.rchild^.flag:=true;
          end;
        p^.delta:=1;
        p^.flag:=false;
      end;
  end;

procedure plus(l1,r1:longint;num:extended);
  var left,right:longint;
    procedure doit(p:tree);
      var l,r:longint;
      begin
        l:=p^.left;
        r:=p^.right;
        if (l>right) or (r<left) then exit;
        if (left=l) and (r<=right) then
          begin
            p^.num:=p^.num*num;
            p^.delta:=p^.delta*num;
            p^.flag:=true;
            downit(p);
            left:=r+1;
          end
        else
          if p^.lchild<>nil then
            begin
              doit(p^.lchild);
              doit(p^.rchild);
            end;
      end;
  begin
    left:=l1;
    right:=r1;
    doit(root);
  end;

function getc(s:longint):extended;
  var p:tree;
  begin
    p:=root;
    while p^.lchild<>nil do
      begin
        downit(p);
        if p^.lchild^.right>=s then p:=p^.lchild else p:=p^.rchild;
      end;
    exit(p^.num);
  end;

begin
  randomize;
  readln(n,m);
  for i:=1 to n do
    readln(a[i],h[i],l[i],r[i]);
  for i:=1 to m do
    readln(b[i],z[i]);
  sort(1,m);
  maketree(1,m,root);
  for i:=1 to n do
    begin
      c:=a[i]-h[i];
      left:=1;
      right:=m;
      repeat
        mid:=(left+right) div 2;
        if b[mid]>=c then right:=mid-1 else left:=mid+1;
      until left>right;
      l1:=left;
      left:=1;
      right:=m;
      repeat
        mid:=(left+right) div 2;
        if b[mid]<=a[i]-1 then left:=mid+1 else right:=mid-1;
      until left>right;
      r1:=right;
      if l1<=r1 then plus(l1,r1,(1-l[i]/100));
      c:=a[i]+h[i];
      left:=1;
      right:=m;
      repeat
        mid:=(left+right) div 2;
        if b[mid]>=a[i]+1 then right:=mid-1 else left:=mid+1;
      until left>right;
      l1:=left;
      left:=1;
      right:=m;
      repeat
        mid:=(left+right) div 2;
        if b[mid]<=c then left:=mid+1 else right:=mid-1;
      until left>right;
      r1:=right;
      if l1<=r1 then plus(l1,r1,(1-r[i]/100));
    end;
  sum:=0;
  for i:=1 to m do
    sum:=sum+getc(i)*z[i];
  writeln(sum:0:20);
end.