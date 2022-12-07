var
 s:string;
 p,q:longint;

function norm(s:string):boolean;
var
 i:longint;
begin
 if (length(s)>16)or(s='')then exit;
 norm:=false;
 for i:=1 to length(s) do if not (s[i]in['a'..'z','A'..'Z','0'..'9','_'])then exit;
 norm:=true;
end;

procedure er;
begin
 writeln('NO');
 halt;
end;

begin
 readln(s);
 p:=pos('@',s);
 if p=0 then er;
 if (p>17)or(p=1) then er;
 if not norm(copy(s,1,p-1))then er;
 delete(s,1,p);
 p:=pos('/',s);
 if p>0 then
 begin
  if (p>33)or(p=1) then er;
  while s[1]<>'/' do
  begin
   q:=pos('.',s);
   if q=1 then er;
   if q=0 then
   begin
    q:=pos('/',s);
    if q=1 then er;
    if not norm(copy(s,1,q-1))then er;
    delete(s,1,q);
    break;
   end;
   if not norm(copy(s,1,q-1)) then er;
   delete(s,1,q);
  end;
  if (length(s)>16)or(s='') then er;
  if not norm(s)then er;
 end else
 begin
  if (length(s)>32)or(s='') then er;
  while s<>'#30' do
  begin
   if s='' then er;
   q:=pos('.',s);
   if q=1 then er;
   if q=0 then
   begin
    if not norm(s)then er;
    break;
   end;
   if q=1 then er;
   if not norm(copy(s,1,q-1)) then er;
   delete(s,1,q);
  end;
 end;
 writeln('YES');
end.