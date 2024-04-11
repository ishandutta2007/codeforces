{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
//{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;
var s:string;
    x,y,i:int;
    ws:array[-200..200,-200..200]of int;
begin
  //reset(input,'b.in');
  //rewrite(output,'b.out');
  readln(s);
  x:=0;
  y:=0;
  for i:=1 to length(s) do begin
    ws[x][y]:=i;
    case s[i] of
    'L':begin
      dec(x);
    end;
    'R':begin
      inc(x);
    end;
    'U':begin
      inc(y);
    end;
    'D':begin
      dec(y);
    end;
    end;
    if ws[x][y]<>0 then begin
      writeln('BUG');
      halt;
    end;
  end;
  x:=0;
  y:=0;
  for i:=1 to length(s) do begin
    case s[i] of
    'L':begin
      dec(x);
    end;
    'R':begin
      inc(x);
    end;
    'U':begin
      inc(y);
    end;
    'D':begin
      dec(y);
    end;
    end;
    if (ws[x-1][y]<>0)and(ws[x-1][y]<i-1) then begin
      writeln('BUG');
      halt;
    end;
    if (ws[x+1][y]<>0)and(ws[x+1][y]<i-1) then begin
      writeln('BUG');
      halt;
    end;
    if (ws[x][y-1]<>0)and(ws[x][y-1]<i-1) then begin
      writeln('BUG');
      halt;
    end;
    if (ws[x][y+1]<>0)and(ws[x][y+1]<i-1) then begin
      writeln('BUG');
      halt;
    end;
  end;
  writeln('OK');
end.