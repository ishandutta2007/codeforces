{$APPTYPE CONSOLE}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$D+,I+,L+,Q+,R+,S+,O-,H+}

uses
  SysUtils,Math;
type int=longint;
var n,k,i,kk,j,kp:int;
    bol:boolean;
    p:array[0..10000]of int;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(n,k);
  kp:=0;
  for i:=2 to n do begin
    bol:=true;
    for j:=2 to i-1 do if i mod j=0 then begin
      bol:=false;
      break;
    end;
    if bol then begin
      inc(kp);
      p[kp]:=i;
      //writeln(i);
    end;
  end;
  kk:=0;
  for i:=1 to kp-1 do begin
    for j:=1 to kp do
    if p[i]+p[i+1]+1=p[j] then inc(kk);
  end;
  if kk>=k then writeln('YES')
           else writeln('NO');
end.