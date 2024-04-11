{$APPTYPE CONSOLE}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
//{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$MAXSTACKSIZE 1000000000}
uses
  SysUtils,Math;
type int=longint;
var x:int64;
    i:int;
begin
  readln(x);
  x:=abs(x);
  for i:=0 to 1000000 do begin
    if int64(i)*(i+1) div 2>=x then begin
      if (int64(i)*(i+1) div 2-x)mod 2=0 then begin
        writeln(i);
        halt;
      end;
    end;
  end;
end.