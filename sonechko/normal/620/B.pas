uses math;
const a:array[0..9]of longint=(6,2,5,5,4,5,6,3,7,6);
var x1,y1,x2,y2,l,r,ans,i:longint;
  begin
    read(x1,y1);
    for i:=x1 to y1 do
     begin
       l:=i;
       while l mod 10=0 do
        begin
          ans:=ans+a[0];
          l:=l div 10;
        end;
       while l>0 do
        begin
          ans:=ans+a[l mod 10];
          l:=l div 10;
        end;
     end;
    writeln(ans);
  end.