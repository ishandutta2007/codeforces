{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
//{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;
var n,p1,p2,p3,t1,t2,ans:int64;
    i:int;
    l,r:array[0..10000]of int;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(n,p1,p2,p3,t1,t2);
  for i:=1 to n do begin
    read(l[i],r[i]);
  end;
  ans:=0;
  for i:=1 to n do begin
    ans:=ans+p1*(r[i]-l[i]);
  end;
  for i:=1 to n-1 do begin
    if l[i+1]-r[i]<=t1 then begin
      ans:=ans+p1*(l[i+1]-r[i]);
    end else
    if l[i+1]-r[i]<=t1+t2 then begin
      ans:=ans+p1*(t1)+p2*(l[i+1]-r[i]-t1);
    end else begin
      ans:=ans+p1*(t1)+p2*(t2)+p3*(l[i+1]-r[i]-t1-t2);
    end;
  end;
  writeln(ans);
end.