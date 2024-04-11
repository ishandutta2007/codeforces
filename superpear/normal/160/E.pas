type avl=^pear;
     pear=record
            lchild,rchild:avl;
            num,where,depth:longint;
          end;

     tree=^gobble;
     gobble=record
              left,right:longint;
              lchild,rchild:tree;
              root:avl;
            end;

var x,y,t,w,x1,y1,t1,w1,ans,bak,m1:array[0..200000] of longint;
    root:tree;
    null:avl;
    m,n,i,left,right,mid,last,min,mink,s:longint;

function max(a,b:longint):longint;
  begin
    if a>b then exit(a) else exit(b);
  end;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort1(l,r:longint);
  var i,j,c:longint;
  begin
    i:=l;
    j:=r;
    c:=x[l+random(r-l+1)];
    repeat
      while x[i]<c do inc(i);
      while c<x[j] do dec(j);
      if i<=j then
        begin
          swap(x[i],x[j]);
          swap(y[i],y[j]);
          swap(t[i],t[j]);
          swap(w[i],w[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort1(l,j);
    if i<r then sort1(i,r);
  end;

procedure sort2(l,r:longint);
  var i,j,c:longint;
  begin
    i:=l;
    j:=r;
    c:=bak[l+random(r-l+1)];
    repeat
      while bak[i]<c do inc(i);
      while c<bak[j] do dec(j);
      if i<=j then
        begin
          swap(bak[i],bak[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort2(l,j);
    if i<r then sort2(i,r);
  end;

procedure sort3(l,r:longint);
  var i,j,c:longint;
  begin
    i:=l;
    j:=r;
    c:=x1[l+random(r-l+1)];
    repeat
      while x1[i]<c do inc(i);
      while c<x1[j] do dec(j);
      if i<=j then
        begin
          swap(x1[i],x1[j]);
          swap(y1[i],y1[j]);
          swap(t1[i],t1[j]);
          swap(w1[i],w1[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort3(l,j);
    if i<r then sort3(i,r);
  end;

procedure maketree(var node:tree;left,right:longint);
  var p:tree;
      q:avl;
  begin
    new(p);
    p^.left:=left;
    p^.right:=right;
    p^.lchild:=nil;
    p^.rchild:=nil;
    new(q);
    q^.lchild:=null;
    q^.rchild:=null;
    q^.depth:=1;
    q^.num:=maxlongint;
    q^.where:=0;
    p^.root:=q;
    node:=p;
    if left=right then exit else
      begin
        maketree(node^.lchild,left,(left+right) div 2);
        maketree(node^.rchild,(left+right) div 2+1,right);
      end;
  end;

procedure update(p:avl);
  begin
    if p<>null then
      p^.depth:=max(p^.lchild^.depth,p^.rchild^.depth)+1;
  end;

procedure swapt(var a,b:avl);
  var r:avl;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure spinl(var a:avl);
  var b:avl;
  begin
    b:=a^.lchild;
    a^.lchild:=b^.rchild;
    b^.rchild:=a;
    update(a);
    update(b);
    swapt(a,b);
  end;

procedure spinr(var a:avl);
  var b:avl;
  begin
    b:=a^.rchild;
    a^.rchild:=b^.lchild;
    b^.lchild:=a;
    update(a);
    update(b);
    swapt(a,b);
  end;

procedure incert(var node:avl;num1,num2:longint);
  var p:avl;
  begin
    if node=null then
      begin
        new(p);
        p^.lchild:=null;
        p^.rchild:=null;
        p^.depth:=1;
        p^.num:=num1;
        p^.where:=num2;
        node:=p;
      end
    else
      begin
        if num1<node^.num then incert(node^.lchild,num1,num2)
                          else incert(node^.rchild,num1,num2);
        if abs(node^.lchild^.depth-node^.rchild^.depth)>=2 then
          begin
            if node^.lchild^.depth>node^.rchild^.depth then
              spinl(node)
            else
              spinr(node);
          end;
        update(node);
      end;
  end;

procedure incertall(node:tree;place,num1,num2:longint);
  var l,r:longint;
  begin
    l:=node^.left;
    r:=node^.right;
    if (l>place) or (r<place) then exit;
    incert(node^.root,num1,num2);
    if node^.lchild<>nil then
      begin
        incertall(node^.lchild,place,num1,num2);
        incertall(node^.rchild,place,num1,num2);
      end;
  end;

procedure findall(left,right,mini:longint);
    procedure search(p:tree);
      var l,r:longint;
          q:avl;
      begin
        l:=p^.left;
        r:=p^.right;
        if (l>right) or (r<left) then exit;
        if (l=left) and (r<=right) then
          begin
            q:=p^.root;
            while q<>null do
              begin
                if q^.num>=mini then
                  begin
                    if q^.num<min then
                      begin
                        min:=q^.num;
                        mink:=q^.where;
                      end;
                    q:=q^.lchild;
                  end
                else
                  q:=q^.rchild;
              end;
            left:=r+1;
          end
        else
          if p^.lchild<>nil then
            begin
              search(p^.lchild);
              search(p^.rchild);
            end;
      end;
  begin
    search(root);
  end;

begin
  new(null);
  null^.lchild:=null;
  null^.rchild:=null;
  null^.depth:=0;
  null^.num:=0;
  null^.where:=0;

  randomize;

  readln(n,m);
  for i:=1 to n do
    begin
      readln(x[i],y[i],t[i]);
      w[i]:=i;
    end;
  sort1(1,n);
  for i:=1 to m do
    begin
      readln(x1[i],y1[i],t1[i]);
      w1[i]:=i;
    end;
  for i:=1 to n do
    bak[i]:=y[i];
  for i:=1 to m do
    bak[n+i]:=y1[i];
  sort2(1,n+m);
  m1[0]:=0;
  bak[0]:=-1;
  for i:=1 to n+m do
    if bak[i]=bak[i-1] then m1[i]:=m1[i-1] else m1[i]:=m1[i-1]+1;
  s:=m1[n+m];
  for i:=1 to n do
    begin
      left:=1;
      right:=n+m;
      repeat
        mid:=(left+right) div 2;
        if bak[mid]=y[i] then break;
        if bak[mid]>y[i] then right:=mid-1 else left:=mid+1;
      until false;
      y[i]:=m1[mid];
    end;
  for i:=1 to m do
    begin
      left:=1;
      right:=n+m;
      repeat
        mid:=(left+right) div 2;
        if bak[mid]=y1[i] then break;
        if bak[mid]>y1[i] then right:=mid-1 else left:=mid+1;
      until false;
      y1[i]:=m1[mid];
    end;
  sort3(1,m);

  root:=nil;
  maketree(root,1,s);
  last:=0;
  for i:=1 to m do
    begin
      while (last<n) and (x[last+1]<=x1[i]) do
        begin
          inc(last);
          incertall(root,y[last],t[last],w[last]);
        end;
      min:=maxlongint;
      mink:=-1;
      findall(y1[i],s,t1[i]);
      ans[w1[i]]:=mink;
    end;
  for i:=1 to m-1 do
    write(ans[i],' ');
  writeln(ans[m]);
end.