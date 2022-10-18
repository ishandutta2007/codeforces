var n,q:longint;
    st:ansistring;
function first(s:ansistring):boolean;
var b,b2:boolean;
    j:longint;
 begin
   b:=false;
   b2:=false;
   for j:=1 to length(s) do
    begin
     if s[j] in ['0'..'9'] then
      begin
       b2:=true;
       if b then exit(true);
      end else
     if b2 then b:=true;
    end;
   exit(false);
 end;
function second(s:ansistring):ansistring;
var i,a,b,c,d:longint;
    bol:boolean;
    ans,r:ansistring;
 begin
    bol:=true;
    a:=0;
    b:=0;
    for i:=1 to length(s) do
     if s[i]='C' then bol:=false else
     if s[i] in ['0'..'9'] then
      begin
       val(s[i],c);
       if bol then a:=a*10+c else
        b:=b*10+c;
      end;
    ans:='';
    while b>0 do
     begin
      if b mod 26=0 then ans:='Z'+ans else ans:=chr(ord(b mod 26)+64)+ans;
      b:=b div 26;
      if ans[1]='Z' then dec(b);
     end;
    str(a,r);
    exit(ans+r);
 end;
function first1(s:ansistring):ansistring;
var a, i, b, j: longint;
        st,ans,st2:ansistring;
 begin
   b:=1;
   a:=0;
   for i:=1 to length(s) do
    if s[i] in ['0'..'9'] then
     begin
       st:=copy(s,i,length(s)-i+1);
       for j:=1 to (i-1) do
        a:=a*26+(ord(s[j])-64);
       break;
     end;
   str(a,st2);
   exit('R'+st+'C'+st2);
 end;
begin
  readln(n);
  for q:=1 to n do
   begin
     readln(st);
     if first(st) then writeln(second(st)) else writeln(first1(st));
   end;
end.