var a:array[1..3,1..3]of char;
    n,m,i,j,k,ans,l,r:longint;
    ch1,ch2,h:char;
function ll(h:char):boolean;
  begin
    if (a[1,1]=h) and (a[2,2]=h) and (a[3,3]=h) then exit(true);
    if (a[1,3]=h) and (a[2,2]=h) and (a[3,1]=h) then exit(true);
    if (a[1,1]=h) and (a[1,2]=h) and (a[1,3]=h) then exit(true);
    if (a[2,1]=h) and (a[2,2]=h) and (a[2,3]=h) then exit(true);
    if (a[3,1]=h) and (a[3,2]=h) and (a[3,3]=h) then exit(true);
    if (a[1,1]=h) and (a[2,1]=h) and (a[3,1]=h) then exit(true);
    if (a[1,2]=h) and (a[2,2]=h) and (a[3,2]=h) then exit(true);
    if (a[1,3]=h) and (a[2,3]=h) and (a[3,3]=h) then exit(true);
    exit(false);
  end;
  begin
    for i:=1 to 3 do
     begin
       for j:=1 to 3 do
        begin
         read(a[i,j]);
         if a[i,j]='X' then inc(l);
         if a[i,j]='0' then inc(r);
        end;
       readln;
     end;
    if (ll('X')) and (ll('0')) or (r>l) or (l>r+1) or ((ll('0')) and (l>r)) or ((ll('X')) and (r=l))then writeln('illegal')
                                                                           else
    if (l+r=9) and (ll('X')=false) and (ll('0')=false) then writeln('draw')
                                                       else
    if (ll('X')) then writeln('the first player won')
                 else
    if (ll('0')) then writeln('the second player won')
                 else
    if l=r then writeln('first')
           else writeln('second');
  end.