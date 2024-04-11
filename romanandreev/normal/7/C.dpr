{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
//{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;
var a,b,c,x,nd,tk:int64;
    ta,tb,tta,ttb:array[0..10000]of int64;
function nod(a,b:int64):int64;
var c:int64;
begin
  while b<>0 do begin
    c:=a mod b;
    a:=b;
    b:=c;
  end;
  result:=a;
end;
function obr(a,p:int64):int64;
var i:int;
begin
  if nod(abs(a),p)<>1 then begin
    writeln(-1);
    halt;
  end;
  a:=a mod p;
  a:=(a+p) mod p;
  if a=0 then begin
    result:=0;
    exit;
  end;
  ta[1]:=a;
  tb[1]:=p;
  tk:=1;
  while tb[tk]<>0 do begin
    inc(tk);
    ta[tk]:=tb[tk-1];
    tb[tk]:=ta[tk-1] mod tb[tk-1];
  end;
  tta[tk]:=1;
  ttb[tk]:=0;
  for i:=tk-1 downto 1 do begin
    tta[i]:=((-ttb[i+1])mod p+p)mod p;
    ttb[i]:=((-tta[i+1]-ttb[i+1]*(ta[i] div tb[i]))mod p+p)mod p;
  end;
  result:=(tta[1] mod p+p)mod p;
  if a*result mod p<>1 then begin
    writeln(-1);
    halt;
  end;
end;
begin
  //reset(input,'c.in');
  //rewrite(output,'c.out');
  readln(a,b,c);
  nd:=nod(nod(abs(a),abs(b)),abs(c));
  a:=a div nd;
  b:=b div nd;
  c:=c div nd;
  if b<>0 then begin
    if b<0 then begin
      a:=-a;
      b:=-b;
      c:=-c;
    end;
    if a=0 then begin
      if abs(c) mod abs(b)=0 then begin
      writeln(0,' ',-c div b);
      end else writeln(-1);
    end
    else begin
      x:=(-c*obr(a,b))mod b;
      writeln(x,' ',(-c-a*x) div b);
    end;
  end else begin
    if a<0 then begin
      a:=-a;
      b:=-b;
      c:=-c;
    end;
    if b=0 then begin
      if abs(c) mod abs(a)=0 then begin
      writeln(-c div a,' ',0);
      end else writeln(-1);
    end
    else begin
      x:=(-c*obr(b,a))mod a;
      writeln((-c-b*x) div a,' ',x);
    end;
  end;
end.