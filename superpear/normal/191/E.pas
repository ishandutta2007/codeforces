const big=1000000000000000;

type tree=^pear;
     pear=record
            lchild,rchild:tree;
            size,depth:longint;
            num:int64;
          end;

var k,left,right,mid:int64;
    a:array[0..120000] of longint;
    n,i:longint;
    root,null:tree;

function getmax(a,b:longint):longint;
  begin
    if a>b then exit(a) else exit(b);
  end;

procedure update(p:tree);
  begin
    if p<>null then
      begin
        p^.size:=p^.lchild^.size+p^.rchild^.size+1;
        p^.depth:=getmax(p^.lchild^.depth,p^.rchild^.depth)+1;
      end;
  end;

procedure swapt(var a,b:tree);
  var r:tree;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure spinl(var a:tree);
  var b:tree;
  begin
    b:=a^.lchild;
    a^.lchild:=b^.rchild;
    b^.rchild:=a;
    update(a);update(b);
    swapt(a,b);
  end;

procedure spinr(var a:tree);
  var b:tree;
  begin
    b:=a^.rchild;
    a^.rchild:=b^.lchild;
    b^.lchild:=a;
    update(a);update(b);
    swapt(a,b);
  end;

procedure incert(var node:tree;num:int64);
  var p:tree;
  begin
    if node=null then
      begin
        new(p);
        p^.lchild:=null;
        p^.rchild:=null;
        p^.size:=1;
        p^.num:=num;
        p^.depth:=1;
        node:=p;
      end
    else
      begin
        if num<node^.num then
          incert(node^.lchild,num)
        else
          incert(node^.rchild,num);
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

function getans(s:int64):int64;
  var c,ans:int64;
      p:tree;
      i:longint;
  begin
    new(root);
    root^.lchild:=null;
    root^.rchild:=null;
    root^.size:=1;
    root^.num:=-big;
    root^.depth:=1;
    c:=s;
    ans:=0;
    for i:=1 to n do
      begin
        c:=c-a[i];
        incert(root^.rchild,a[i]+c-s);
        p:=root;
        repeat
          if p^.num>=c then
            begin
              ans:=ans+int64(p^.rchild^.size+1);
              p:=p^.lchild;
            end
          else
            p:=p^.rchild;
        until p=null;
      end;
    exit(ans);
  end;

begin
  new(null);
  null^.lchild:=null;
  null^.rchild:=null;
  null^.num:=0;
  null^.size:=0;
  null^.depth:=0;

  readln(n,k);
  for i:=1 to n do
    read(a[i]);
  left:=-big;
  right:=big;
  repeat
    mid:=(left+right) div 2;
    if getans(mid)>=k then left:=mid+1 else right:=mid-1;
  until left>right;
  writeln(right);
end.