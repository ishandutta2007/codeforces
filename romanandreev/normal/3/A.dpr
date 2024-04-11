program Za;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var c1,c2,c3,c4:char;
    x1,y1,x2,y2:integer;
begin
  //reset(input,'a.in');
  //rewrite(output,'a.out');
  readln(c1,c2);
  readln(c3,c4);
  x1:=ord(c1)-ord('a')+1;
  y1:=ord(c2)-ord('1')+1;
  x2:=ord(c3)-ord('a')+1;
  y2:=ord(c4)-ord('1')+1;
  writeln(max(abs(x1-x2),abs(y1-y2)));
  while (x1<>x2)or(y1<>y2) do begin
    if abs(x1-x2)>0 then begin
      if x1<x2 then begin
        write('R');
        inc(x1);
      end else begin
        write('L');
        dec(x1);
      end;
    end;
    if abs(y1-y2)>0 then begin
      if y1<y2 then begin
        write('U');
        inc(y1);
      end else begin
        write('D');
        dec(y1);
      end;
    end;
    writeln;
  end;
end.