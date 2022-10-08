{$MODE DELPHI}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$M 1000000000}
Uses Math,SysUtils;
type int=longint;
var s,s1,s2,s3,ss:string;
	x,y,i:int;
	good:set of char;
function goods(s:string):boolean;
var i:int;
begin
	result:=false;
	if length(s)<1 then exit;
	if length(s)>16 then exit;
	for i:=1 to length(s) do if not(s[i] in good) then exit;
	result:=true;
end;
begin
	{assign(input,'a.in');
	reset(input);
	assign(output,'a.out');
	rewrite(output);}
	readln(s);
	x:=pos('@',s);
	if x=0 then begin
		writeln('NO');
		halt;
	end;
	s1:=copy(s,1,x-1);
	delete(s,1,x);
	if pos('@',s)<>0 then begin
		writeln('NO');
		halt;
	end;
	x:=pos('/',s);
	if x=0 then begin 
		s2:=s;
		s3:='a';
	end else begin
		s2:=copy(s,1,x-1);
		delete(s,1,x);
		s3:=s;
	end;
	good:=['a'..'z','A'..'Z','0'..'9','_'];
	if not goods(s1) then begin
		writeln('NO');
		halt;
	end;
	if not goods(s3) then begin
		writeln('NO');
		halt;
	end;
	ss:='';
	if length(s2)>32 then begin
		writeln('NO');
		halt;
	end;
	if length(s2)=0 then begin
		writeln('NO');
		halt;
	end;
	s2:=s2+'.';
	for i:=1 to length(s2) do begin
		if s2[i]='.' then begin
			//writeln(erroutput,ss);
			if not goods(ss) then begin
				writeln('NO');
				halt;
			end;
			ss:='';
		end else 
			ss:=ss+s2[i];
	end;
	writeln('YES');
end.