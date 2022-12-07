var
 s:string;
 a:array[-100..100,-100..100]of longint;
 x,y,i:longint;
begin
 readln(s);
 fillchar(a,sizeof(a),127);
 x:=0;
 y:=0;
 a[0,0]:=0;
 for i:=2 to length(s) do 
 if (s[i]='U')and(s[i-1]='D')or(s[i]='D')and(s[i-1]='U')or
 (s[i]='L')and(s[i-1]='R')or(s[i]='R')and(s[i-1]='L')then
 begin
  writeln('BUG');
  halt;
 end;
 for i:=1 to length(s) do
 begin
  case s[i] of
   'L':inc(x);
   'R':dec(x);
   'U':inc(y);
   'D':dec(y);
  end;
  a[x,y]:=i;
  if a[x-1,y]+1<i then
  begin
   writeln('BUG');
   halt;
  end;
  if a[x+1,y]+1<i then
  begin
   writeln('BUG');
   halt;
  end;
  if a[x,y-1]+1<i then
  begin
   writeln('BUG');
   halt;
  end;
  if a[x,y+1]+1<i then
  begin
   writeln('BUG');
   halt;
  end;
 end;
 writeln('OK');
end.