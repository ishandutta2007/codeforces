program D_;
{$inline on}
var a,v,l,d,w:longint;
    tw,dw:extended;
function di(p,t:extended):extended;inline;
  begin
    di:=p*t+a*t*t/2;
  end;
function tt(d,p:extended):extended;inline;
  var tm,ta:extended;
  begin
    ta:=(-p+sqrt(p*p+2*a*d))/a;
    tm:=(v-p)/a;
    if tm>ta then exit(ta) else exit(tm+(d-di(p,tm))/v);
  end;
begin
//  assign(input,'D.in');reset(input);
//  assign(output,'D.out');rewrite(output);
  readln(a,v,l,d,w);
  if v<=w then writeln(tt(l,0):0:12)else
    begin
      tw:=w/a;
      dw:=di(0,tw);
      if dw>d then writeln(tt(l,0):0:12) else
      writeln(tw+2*tt((d-dw)/2,w)+tt(l-d,w):0:12);
    end;
//  close(input);close(output);
end.