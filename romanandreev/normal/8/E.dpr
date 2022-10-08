{$APPTYPE CONSOLE}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
uses
  SysUtils,Math;
type int=longint;
var n,i,j,kk:int;
    s:string;
    k,ff:int64;
function inv(s:string):string;
var i:int;
begin
  result:='';
  for i:=1 to n do begin
    if s[i]='0' then
      result:=result+'1';
    if s[i]='1' then
      result:=result+'0';
    if s[i]='2' then
      result:=result+'2';
  end;
end;
function rev(s:string):string;
var i:int;
begin
  result:='';
  for i:=n downto 1 do
    result:=result+s[i];
end;
function good(s:string):boolean;
begin
  result:=(s<=rev(s))and(s<=inv(rev(s)));
end;
function calc0(s:string):int64;
var ff,k0,i:int;
begin
  result:=0;
  ff:=0;
  k0:=0;
  for i:=n downto 1 do if s[i]='2' then begin
    ff:=i;
    break;
  end;
  for i:=1 to n do if s[i]='2' then inc(k0);
  if ff<>0 then begin
    if s[n-ff+1]='0' then begin
      s[ff]:='0';
      result:=result+calc0(s)+(int64(1) shl (k0-1));
      s[ff]:='2';
    end;
    if s[n-ff+1]='1' then begin
      s[ff]:='1';
      result:=result+calc0(s);
      s[ff]:='2';
    end;
    if s[n-ff+1]='2' then begin
      if ff=n-ff+1 then result:=2 else begin
        s[ff]:='0';
        s[n-ff+1]:='0';
        result:=2*calc0(s)+int64(1) shl (k0-2);
        s[ff]:='2';
        s[n-ff+1]:='2';
      end;
    end;
  end else begin
    if good(s) then
      result:=1;
  end;
end;
function calc1(s:string):int64;
var ff,k0,i:int;
begin
  result:=0;
  ff:=0;
  k0:=0;
  for i:=n downto 1 do if s[i]='2' then begin
    ff:=i;
    break;
  end;
  for i:=1 to n do if s[i]='2' then inc(k0);
  if ff<>0 then begin
    if s[n-ff+1]='0' then begin
      s[ff]:='1';
      result:=result+calc1(s)+(int64(1) shl (k0-1));
      s[ff]:='2';
    end;
    if s[n-ff+1]='1' then begin
      s[ff]:='0';
      result:=result+calc1(s);
      s[ff]:='2';
    end;
    if s[n-ff+1]='2' then begin
      if ff=n-ff+1 then result:=1 else begin
        s[ff]:='1';
        s[n-ff+1]:='0';
        result:=2*calc1(s)+int64(1) shl (k0-2);
        s[ff]:='2';
        s[n-ff+1]:='2';
      end;
    end;
  end else begin
    if good(s) then
      result:=1;
  end;
end;
function calc(s:string):int64;
var i:int;
begin
  result:=0;
  if length(s)=n then begin
    if good(s) then
      result:=1;
    exit;
  end;
  for i:=length(s)+1 to n do s:=s+'2';
  s[n]:='0';
  result:=result+calc0(s);
  s[n]:='1';
  result:=result+calc1(s);
end;
begin
 // reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(n,k);
  s:='0';
  for i:=2 to n do begin
    s:=s+'0';
    ff:=calc(s);
    if ff<=k then begin
      s[i]:='1';
      k:=k-ff;
    end;
  end;
  if (not good(s))or(k>0) then
    writeln(-1)
  else
    writeln(s);
end.