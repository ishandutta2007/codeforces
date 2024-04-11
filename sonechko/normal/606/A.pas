var n,m,k,l,r,g,ii,jj:longint;
  begin
    read(n,m,k,l,r,g);
    while n<l do
     begin
       if m-2>=r then begin inc(n); dec(m,2); end else
       if k-2>=g then begin inc(n); dec(k,2); end else begin writeln('No'); halt; end;
     end;
    while m<r do
     begin
       if n-2>=l then begin inc(m); dec(n,2); end else
       if k-2>=g then begin inc(m); dec(k,2); end else begin writeln('No'); halt; end;
     end;
    while k<g do
     begin
       if n-2>=l then begin inc(k); dec(n,2); end else
       if m-2>=r then begin inc(k); dec(m,2); end else begin writeln('No'); halt; end;
     end;
    writeln('Yes');
  end.