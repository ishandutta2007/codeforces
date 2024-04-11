{$APPTYPE CONSOLE}
uses Math,SysUtils;
var n,k,i,eps:longint;
	l,r,m,x0,y0:extended;
	eps1:extended;
	a:array[0..100,0..100] of extended;
    sp:array[1..100] of extended;
    x,y:array[1..100]of extended;
function ok(u:extended):extended;
var res:extended;
	i:longint;
  j: longint;
begin
	res:=0;
    for i := 1 to n do begin
    	if u=0 then
        	if (x[i]=x0)and(y[i]=y0) then sp[i]:=1 else sp[i]:=0
        else begin
        	if (x[i]-x0)*(x[i]-x0)+(y[i]-y0)*(y[i]-y0) <= u*u then sp[i]:=1
            else
        	sp[i] := exp(1-((x[i]-x0)*(x[i]-x0)+(y[i]-y0)*(y[i]-y0))/(u*u));
        end;
    end;
    for i := 1 to n do
    	a[0][i]:=0;
    a[0][0]:=1;
    for i := 1 to n do begin
    	a[i][0]:=a[i-1][0]*(1-sp[i]);
        for j := 1 to n do
        	a[i][j]:=a[i-1][j]*(1-sp[i]) + a[i-1][j-1]*(sp[i]);
    end;
    for i := k to n do
    	res:=res+a[n][i];
    ok:=res;
end;
begin
	//assign(input,'input.txt');
	readln(n);
    readln(k,eps);
    readln(x0,y0);
    for i := 1 to n do
    readln(x[i],y[i]);
    eps1:=(1000-eps)/1000;
    if ok(0) >= eps1 then writeln(0) else begin
    	l:=0;
        r:=100000;
        while (r-l > 1e-8) do begin
        	m:=(l+r)/2;
            if ok(m) >= eps1 then r:=m else l:=m;
        end;
        writeln(r:0:15);
        //m:=3.84257761518762740;
        //writeln(ok(m):0:10);
    end;
//	readln;
end.