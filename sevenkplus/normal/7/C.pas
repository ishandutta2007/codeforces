program C_;
{$inline on}
var a,b,c:int64;
function exgcd(a,b:int64;var x,y:int64):int64;
  var t,d:int64;
  begin
    if b=0 then
      begin
        x:=1;y:=0;exit(a);
      end;
    d:=exgcd(b,a mod b,x,y);
    t:=x;x:=y;y:=t-a div b*y;
    exit(d);
  end;
procedure mle(a,b,n:int64);inline;
  var d,x,y:int64;
  begin
    d:=exgcd(a,n,x,y);
    if b mod d<>0 then writeln(-1) else
      writeln(b div d*x,' ',b div d*y);
  end;
begin
//  assign(input,'C.in');reset(input);
//  assign(output,'C.out');rewrite(output);
  while not eof do
    begin
      readln(a,b,c);mle(a,-c,b);
    end;
//  close(input);close(output);
end.