uses math;
var q1,q2,w1,w2:char;
    n,m,i,j,k,l,r,x1,x2,y1,y2:longint;
  begin
    readln(q1,q2);
    readln(w1,w2);
    x1:=ord(q1)-96;
    y1:=ord(q2)-48;
    x2:=ord(w1)-96;
    y2:=ord(w2)-48;
    writeln(max(abs(x1-x2),abs(y1-y2)));
    while (x1<>x2) or (y1<>y2) do
     begin
       if x2>x1 then begin write('R'); inc(x1); end;
       if x2<x1 then begin write('L'); dec(x1); end;
       if y2>y1 then begin write('U'); inc(y1); end;
       if y2<y1 then begin write('D'); dec(y1); end;
       writeln;
     end;
  end.