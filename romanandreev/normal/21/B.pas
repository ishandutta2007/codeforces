{$MODE DELPHI}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$M 1000000000}
Uses Math,SysUtils;
type int=longint;
var a1,a2,b1,b2,c1,c2,d1,dx,dy,t1,t2:int;
function typea(a,b,c:int):int;
begin
	if (a=0)and(b=0)and(c=0) then result:=2 else
	if (a=0)and(b=0)and(c<>0) then result:=0 else
	result:=1;
end;
begin
	{assign(input,'b.in');
	reset(input);
	assign(output,'b.out');
	rewrite(output);}
	readln(a1,b1,c1);
	readln(a2,b2,c2);
	t1:=typea(a1,b1,c1);
	t2:=typea(a2,b2,c2);
	if (t1=0)or(t2=0) then begin
		writeln(0);
		halt;
	end;
	if (t1=2)or(t2=2) then begin
		writeln(-1);
		halt;
	end;
	d1:=a1*b2-a2*b1;
	if d1=0 then begin
		dx:=c1*b2-c2*b1;
		dy:=a1*c2-c1*a2;
		if (dx=0)and(dy=0) then writeln(-1) else writeln(0);
	end else 
		writeln(1);
end.