{$inline on}
type tree=^pear;
     pear=record
            left,right,up,down,four,seven:longint;
            lchild,rchild:tree;
            switch:boolean;
          end;

var root:tree;
    m,n,i,j,x1,y1:longint;
    ch:char;
    a:array[0..1000000] of longint;

function max(a,b:longint):longint;inline;
  begin
    if a>b then exit(a) else exit(b);
  end;

procedure swap(var a,b:longint);inline;
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure update(p:tree);inline;
  begin
    p^.four:=p^.lchild^.four+p^.rchild^.four;
    p^.seven:=p^.lchild^.seven+p^.rchild^.seven;
    p^.up:=max(p^.lchild^.four+p^.rchild^.up,p^.lchild^.up+p^.rchild^.seven);
    p^.down:=max(p^.lchild^.seven+p^.rchild^.down,p^.lchild^.down+p^.rchild^.four);
  end;

procedure downit(p:tree);inline;
  begin
    if p^.switch then
      begin
        p^.switch:=false;
        if p^.lchild<>nil then
          begin
            p^.lchild^.switch:=not p^.lchild^.switch;
            p^.rchild^.switch:=not p^.rchild^.switch;
            swap(p^.lchild^.four,p^.lchild^.seven);
            swap(p^.lchild^.up,p^.lchild^.down);
            swap(p^.rchild^.four,p^.rchild^.seven);
            swap(p^.rchild^.up,p^.rchild^.down);
          end;
      end;
  end;

procedure maketree(var node:tree;left,right:longint);
  var p:tree;
  begin
    new(p);
    p^.lchild:=nil;
    p^.rchild:=nil;
    p^.left:=left;
    p^.right:=right;
    p^.switch:=false;
    node:=p;
    if left=right then
      begin
        if a[left]=4 then
          begin
            p^.four:=1;
            p^.seven:=0;
          end
        else
          begin
            p^.four:=0;
            p^.seven:=1;
          end;
        p^.up:=1;
        p^.down:=1;
      end
    else
      begin
        maketree(node^.lchild,left,(left+right) div 2);
        maketree(node^.rchild,(left+right) div 2+1,right);
        update(node);
      end;
  end;

procedure switch(left,right:longint);inline;
    procedure search(p:tree);
      var l,r:longint;
      begin
        l:=p^.left;
        r:=p^.right;
        if (l>right) or (r<left) then exit;
        downit(p);
        if (left<=l) and (r<=right) then
          begin
            swap(p^.four,p^.seven);
            swap(p^.up,p^.down);
            p^.switch:=not p^.switch;
            downit(p);
          end
        else
          if p^.lchild<>nil then
            begin
              search(p^.lchild);
              search(p^.rchild);
              update(p);
            end;
      end;
  begin
    search(root);
  end;

begin
  readln(n,m);
  for i:=1 to n do
    begin
      read(ch);
      if ch='4' then a[i]:=4 else a[i]:=7;
    end;
  readln;
  root:=nil;
  maketree(root,1,n);
  for i:=1 to m do
    begin
      read(ch);
      if ch='c' then
        begin
          readln;
          writeln(root^.up);
        end
      else
        begin
          for j:=1 to 5 do read(ch);
          readln(x1,y1);
          switch(x1,y1);
        end;
    end;
end.