{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;
var n,i:int;
    m,x,ans,t:int64;
function sum(x:int64):int64;
var i:int;
begin
  result:=0;
  if x mod 4=1 then
    result:=1;
  if x mod 4=2 then
    result:=1;
  for i:=60 downto 2 do begin
    if (x shr (i-1))and 1=1 then begin
      t:=(x-(int64(1) shl (i-1))+1)and 1;
      result:=result or (t shl (i-1));
      x:=x xor (int64(1) shl (i-1));
    end;
  end;
end;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(n);
  ans:=0;
  for i:=1 to n do begin
    read(m,x);
    ans:=ans xor sum(m+x-1) xor sum(m-1);
  end;
  if ans=0 then writeln('bolik')
           else writeln('tolik');
end.