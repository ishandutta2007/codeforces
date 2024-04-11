var
 i,j,k,l,n,m,o,p,x,y,a,b,x1,y1,x2,y2,s,mx,my:int64;
 bx,by:boolean;
function gcd(a,b:int64):int64;
 begin
  if a mod b=0 then exit(b);
  if a<b then exit(gcd(b,a));
  exit(gcd(a mod b,b));
 end;
begin
 readln(n,m,x,y,a,b);
 o:=gcd(a,b);
 a:=a div o;
 b:=b div o;
 x1:=0;
 y1:=0;
 if (n div a)*b<=m then begin x2:=n div a*a;y2:=n div a*b;s:=(x2-x1)*y2 end;
 if (m div b)*a<=n then if (m div b)*b*(m div b)*a>s then begin x2:=(m div b)*a;y2:=(m div b)*b;end;
 o:=x2-x1;
 if ((n-x)>=o shr 1)and(x>=o shr 1) then begin
                        bx:=true;
                        if not(odd(o)) then begin x1:=x1+x-(x2-x1)shr 1;x2:=x1+o;;end
                                       else begin x1:=x1+x-o shr 1-1;x2:=x1+o;end;
                        end;
 o:=y2-y1;
 if ((m-y)>=o shr 1)and(y>=o shr 1) then begin
                        by:=true;
                        if not(odd(o)) then begin y1:=y1+y-(y2-y1)shr 1;y2:=y1+o;;end
                                       else begin y1:=y1+y-o shr 1-1;y2:=y1+o;end;
                        end;
 if y1<0 then begin inc(y1);inc(y2);end;
 if x1<0 then begin inc(x1);inc(x2);end;
 mx:=(x1+x2)shr 1;
 my:=(y1+y2)shr 1;
 o:=x2-x1;
 if bx=false then
  if mx<x then
   begin
    x2:=n;
    x1:=n-o;
   end;
 o:=(y2-y1);
 if by=false then
  if my<y then
   begin
    y2:=m;
    y1:=m-o;
   end;
 if (x1=x2)and(y1=y2) then begin x1:=0;y1:=0;x2:=0;y2:=0;end;
 writeln(x1,' ',y1,' ',x2,' ',y2);
end.