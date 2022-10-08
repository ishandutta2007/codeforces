{$MODE DELPHI}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$M 1000000000}
Uses Math,SysUtils;
type int=longint;
var a,s,lf:array[0..1000000]of int64;
	i,j,n:int;
	ans:int64;
begin
	{assign(input,'c.in');
	reset(input);
	assign(output,'c.out');
	rewrite(output);}
	readln(n);
	for i:=1 to n do begin
		read(a[i]);
	end;
	s[0]:=0;
	for i:=1 to n do s[i]:=s[i-1]+a[i];
	if s[n] mod 3<>0 then begin
		writeln(0);
		halt;
	end;
	lf[0]:=0;
	for i:=1 to n do begin 
		lf[i]:=lf[i-1];
		if s[i]=s[n] div 3 then inc(lf[i]);
	end;
	ans:=0;
	for i:=1 to n do if s[n]-s[i-1]=s[n] div 3 then begin	
		ans:=ans+lf[i-2];
	end;
	writeln(ans);
end.