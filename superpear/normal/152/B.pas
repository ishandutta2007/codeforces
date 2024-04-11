var cx,cy,ans:int64;
    m,n,i,left,right,mid,x1,y1,e,xc,yc:longint;
begin
  readln(m,n);
  readln(x1,y1);
  ans:=0;
  readln(e);
  for i:=1 to e do
    begin
      readln(xc,yc);
      left:=1;
      right:=1000000000;
      repeat
        mid:=(int64(left)+right) div 2;
        cx:=int64(x1)+int64(xc)*mid;
        cy:=int64(y1)+int64(yc)*mid;
        if (cx>0) and (cx<=m) and (cy>0) and (cy<=n) then
          left:=mid+1
        else
          right:=mid-1;
      until left>right;
      ans:=ans+int64(right);
      x1:=int64(x1)+int64(xc)*right;
      y1:=int64(y1)+int64(yc)*right;
    end;
  writeln(ans);
end.