type tree=^pear;
     pear=record
            lmax,rmax,nmax,sum:extended;
            lchild,rchild:tree;
            left,right:longint;
          end;

var root:tree;
    n,m,c,i,x1,y1:longint;
    ans:extended;
    x,p,a:array[0..1000000] of extended;

function max(a,b:extended):extended;
  begin
    if a>b then exit(a) else exit(b);
  end;

procedure update(p:tree);
  begin
    p^.sum:=p^.lchild^.sum+p^.rchild^.sum;
    p^.lmax:=max(p^.lchild^.lmax,p^.lchild^.sum+max(0,p^.rchild^.lmax));
    p^.rmax:=max(p^.rchild^.rmax,p^.rchild^.sum+max(0,p^.lchild^.rmax));
    p^.nmax:=max(p^.lchild^.nmax,p^.rchild^.nmax);
    p^.nmax:=max(p^.nmax,max(p^.lchild^.rmax,0)+max(p^.rchild^.lmax,0));
  end;

procedure maketree(var node:tree;left,right:longint);
  var p:tree;
  begin
    new(p);
    p^.lchild:=nil;
    p^.rchild:=nil;
    p^.left:=left;
    p^.right:=right;
    node:=p;
    if left=right then
      begin
        p^.lmax:=a[left];
        p^.rmax:=a[left];
        p^.nmax:=a[left];
        p^.sum:=a[left];
      end
    else
      begin
        maketree(node^.lchild,left,(left+right) div 2);
        maketree(node^.rchild,(left+right) div 2+1,right);
        update(node);
      end;
  end;

function getsum(x,y:longint):extended;
  var ans,last:extended;
    procedure search(node:tree);
      var l,r:longint;
      begin
        l:=node^.left;
        r:=node^.right;
        if (l>y) or (r<x) then exit;
        if (l=x) and (r<=y) then
          begin
            ans:=max(ans,last+max(node^.lmax,node^.sum));
            ans:=max(ans,node^.nmax);
            last:=last+node^.sum;
            if last<0 then last:=0;
            last:=max(last,node^.rmax);
            x:=r+1;
          end
        else
          if node^.lchild<>nil then
            begin
              search(node^.lchild);
              search(node^.rchild);
            end;
      end;
  begin
    ans:=0;
    last:=0;
    search(root);
    exit(ans);
  end;

begin
  readln(n,m,c);
  for i:=1 to n do read(x[i]);
  for i:=1 to n-1 do read(p[i]);
  for i:=1 to n-1 do
    a[i]:=(x[i+1]-x[i])/2-p[i]*c/100;
  dec(n);
  maketree(root,1,n);
  ans:=0;
  for i:=1 to m do
    begin
      readln(x1,y1);
      dec(y1);
      ans:=ans+getsum(x1,y1);
    end;
  writeln(ans:0:10);
end.