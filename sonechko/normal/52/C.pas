uses math;
var n,m,k,ans,l,r:int64;
    i,j:longint;
    v,t:array[0..1000010] of int64;
    s:ansistring;
procedure push(i,l,r:int64);
 var d:int64;
  begin
    t[i*2]:=t[i*2]+t[i];
    t[i*2+1]:=t[i*2+1]+t[i];
    d:=(l+r) div 2;
    v[i*2]:=v[i*2]+t[i];
    v[i*2+1]:=v[i*2+1]+t[i];
    t[i]:=0;
  end;
procedure update(i,l,r,ll,rr,x:int64);
 var d:longint;
  begin
    if (l>rr) or (r<ll) then exit;
    if (ll<=l) and (r<=rr) then
     begin
       t[i]:=t[i]+x;
       v[i]:=v[i]+x;
       exit;
     end;
    d:=(l+r) div 2;
    push(i,l,r);
    update(i*2,l,d,ll,rr,x);
    update(i*2+1,d+1,r,ll,rr,x);
    v[i]:=min(v[i*2],v[i*2+1]);
  end;
function mini(i,l,r,ll,rr:int64):int64;
 var d:longint;
  begin
    if (r<ll) or (l>rr) then exit(1000000000000000000);
    if (ll<=l) and (r<=rr) then exit(v[i]);
    push(i,l,r);
    d:=(l+r) div 2;
    mini:=min(mini(i*2,l,d,ll,rr),mini(i*2+1,d+1,r,ll,rr));
  end;
  begin
    readln(n);
    for i:=1 to n do
     begin
       read(k);
       update(1,1,n,i,i,k);
     end;
    readln;
    readln(m);
    for i:=1 to m do
     begin
       readln(s);
       s:=s+' ';
       val(copy(s,1,pos(' ',s)-1),l);
       delete(s,1,pos(' ',s));
       val(copy(s,1,pos(' ',s)-1),r);
       delete(s,1,pos(' ',s));
       if s<>'' then
        begin
         delete(s,length(s),1);
         val(s,k);
         if l<=r then update(1,1,n,l+1,r+1,k) else
          begin
            update(1,1,n,l+1,n+1,k);
            update(1,1,n,1,r+1,k);
          end;
        end else
        begin
          if l<=r then writeln(mini(1,1,n,l+1,r+1)) else
          writeln(min(mini(1,1,n,l+1,n+1),mini(1,1,n,1,r+1)));
        end;
 
     end;
  end.