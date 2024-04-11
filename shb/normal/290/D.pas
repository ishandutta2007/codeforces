var s,ans:string;
    n,i:longint;
    j:char;

function big(x:char):char;
begin
 if (x<='Z') then exit(x);
 exit(chr(ord(x)-97+65));
end;

function sma(x:char):char;
begin
 if (x>='a') then exit(x);
 exit(chr(ord(x)-65+97));
end;
begin
 readln(s);
 readln(n);
 ans:='';
 for i:=1 to length(s) do if s[i]<='Z' then s[i]:=chr(ord(s[i])-65+97);
 for i:=1 to length(s) do begin
  j:=s[i];
  if (ord(j)<n+97) then ans:=ans+big(j) else ans:=ans+sma(j);
 end;
 writeln(ans); 
end.