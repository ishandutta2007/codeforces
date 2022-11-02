const bigp=1000000007;

var m,n,k,tot,i,rc,fc,e,j,s:longint;
    a,u:array[0..10000] of longint;

begin
  readln(n,m,k);
  tot:=0;
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    if a[i]=0 then
      begin
        inc(tot);
        a[i]:=tot;
        rc:=1;
        fc:=1;
        u[rc]:=i;
        while rc<=fc do
          begin
            for j:=1 to n-k+1 do
              begin
                if (u[rc]>=j) and (u[rc]<=j+k-1) then
                  begin
                    e:=j+j+k-1-u[rc];
                    if a[e]=0 then
                      begin
                        a[e]:=tot;
                        inc(fc);
                        u[fc]:=e;
                      end;
                  end;
              end;
            inc(rc);
          end;
      end;
  s:=1;
  for i:=1 to tot do
    s:=int64(s)*m mod bigp;
  writeln(s);
end.