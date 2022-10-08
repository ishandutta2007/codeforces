{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;

var i,t:int;
    n,m,x1,y1,x2,y2,ans:int64;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(t);
  for i:=1 to t do begin
    read(n,m,x1,y1,x2,y2);
      ans:=n*m-(n-abs(x1-x2))*(m-abs(y1-y2))*2;
    if abs(x1-x2)*2<=n then
    if abs(y1-y2)*2<=m then
      ans:=(abs(x1-x2))*(abs(y1-y2))*2;

    writeln(ans);
  end;
end.