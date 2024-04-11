var l1,r1,l2,r2,ans:longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

function max(a,b:longint):longint;
  begin
    if a>b then exit(a) else exit(b);
  end;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a) else exit(b);
  end;

procedure doit(l1,r1,l2,r2,len:longint);
  var e,mid:longint;
  begin
    if (r1-l1+1<=ans) or (r2-l2+1<=ans) then exit;
    if (l1>l2) or ((l1=l2) and (r1>r2)) then
      begin
        swap(l1,l2);
        swap(r1,r2);
      end;
    //writeln(l1,' ',r1,' ',l2,' ',r2,' ',ans);
    e:=min(r1,r2)-max(l1,l2)+1;
    if e>ans then ans:=e;
    mid:=(len+1)>>1;
    if (l2<=mid) and (mid<=r1) then
      doit(1,r2-mid,l1,mid-1,len div 2)
    else
      if r2<mid then
        doit(l1,r1,l2,r2,len div 2)
      else
        if l1>mid then
          doit(l1-mid,r1-mid,l2-mid,r2-mid,len div 2)
        else
          if l2<=mid then
            begin
              doit(l1,r1,l2,mid-1,len div 2);
              doit(l1,r1,1,r2-mid,len div 2);
            end
          else
            if r1>=mid then
              begin
                doit(l1,mid-1,l2-mid,r2-mid,len div 2);
                doit(1,r1-mid,l2-mid,r2-mid,len div 2);
              end
            else
              doit(l1,r1,l2-mid,r2-mid,len div 2);
  end;

begin
  readln(l1,r1,l2,r2);
  if (l1>l2) or ((l1=l2) and (r1>r2)) then
    begin
      swap(l1,l2);
      swap(r1,r2);
    end;
  ans:=0;
  doit(l1,r1,l2,r2,1<<30-1);
  writeln(ans);
end.