uses math;
var s:ansistring;
    i,j,k,n,m,x,y:longint;
    l,r,ans,tl,tr,res:array[0..4000000]of longint;
procedure update(i,l1,r1:longint);
 var d:longint;
  begin
    if (l1=r1) then
     begin
       ans[i]:=0;
       if s[l1]=')' then r[i]:=1 else l[i]:=1;
       exit;
     end;
    d:=(l1+r1) div 2;
    update(i*2,l1,d);
    update(i*2+1,d+1,r1);
    d:=min(l[i*2],r[i*2+1]);
    ans[i]:=ans[i*2]+ans[i*2+1]+d;
    l[i]:=l[i*2]-d+l[i*2+1];
    r[i]:=r[i*2+1]-d+r[i*2];
  end;
procedure maxi(i,l1,r1,ll,rr:longint);
 var d:longint;
  begin
    if (l1>rr) or (r1<ll) then
     begin
       tl[i]:=0;
       tr[i]:=0;
       res[i]:=0;
       exit;
     end;
    if (l1>=ll) and (r1<=rr) then
     begin
       tl[i]:=l[i];
       tr[i]:=r[i];
       res[i]:=ans[i];
       exit;
     end;
    d:=(l1+r1) div 2;
    maxi(i*2,l1,d,ll,rr);
    maxi(i*2+1,d+1,r1,ll,rr);
    d:=min(tl[i*2],tr[i*2+1]);
    res[i]:=res[i*2]+res[i*2+1]+d;
    tl[i]:=tl[i*2]-d+tl[i*2+1];
    tr[i]:=tr[i*2+1]-d+tr[i*2];
  end;
  begin

    readln(s);
    m:=length(s);
    update(1,1,m);
    readln(n);
    for i:=1 to n do
     begin
       readln(x,y);
       maxi(1,1,m,x,y);
       writeln(res[1]*2);

     end;
  end.