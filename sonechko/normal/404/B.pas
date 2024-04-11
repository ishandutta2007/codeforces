uses math;
const vx:array[0..3]of extended=(1,0,-1,0);
const vy:array[0..3]of extended=(0,1,0,-1);
var n,m,i,j,k,p:longint;
    d,a,x,y,lx,ly,t,l:extended;

  begin
    read(a,d,n);
    k:=0;
    while d>a*4 do
     d:=d-a*4;
    for i:=1 to n do
    begin
     l:=d;
    while (l>0) do
     begin
       lx:=0;
       if (vx[p]>0) then lx:=a-x else if (vx[p]<0) then lx:=x;
       ly:=0;
       if (vy[p]>0) then ly:=a-y else if (vy[p]<0) then ly:=y;
       t:=min(l,max(lx,ly));
       l:=l-t;
       x:=x+vx[p]*t;
       y:=y+vy[p]*t;
       if (vx[p]>0) and (x=a) then p:=(p+1) mod 4
       else
       if (vx[p]<0) and (x=0) then p:=(p+1) mod 4
       else
       if (vy[p]>0) and (y=a) then p:=(p+1) mod 4
       else
       if (vy[p]<0) and (y=0) then p:=(p+1) mod 4;
     end;
    writeln(x:0:10,' ',y:0:10);
    end;
  end.