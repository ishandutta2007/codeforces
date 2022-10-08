{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type int=longint;
var s,ss,a,b:string;
    bol,bol1,bol2:boolean;
    n,i,mx1,mx2,j:int;
begin
  //reset(input,'a.in');
  //rewrite(output,'a.out');
  readln(s);
  n:=length(s);
  readln(a);
  readln(b);
  mx1:=0;
  mx2:=0;
  for i:=1 to n-length(a)+1 do begin
    bol:=true;
    for j:=1 to length(a) do if s[i+j-1]<>a[j] then begin
      bol:=false;
      break;
    end;
    if bol then begin
      mx1:=i;
      break;
    end;
  end;
  for i:=n-length(b)+1 downto 1 do begin
    bol:=true;
    for j:=1 to length(b) do if s[i+j-1]<>b[j] then begin
      bol:=false;
      break;
    end;
    if bol then begin
      mx2:=i;
      break;
    end;
  end;
  bol1:=(mx1<>0)and(mx2<>0)and(mx1+length(a)<=mx2);
  ss:='';
  for i:=n downto 1 do
    ss:=ss+s[i];
  s:=ss;
  mx1:=0;
  mx2:=0;
  for i:=1 to n-length(a)+1 do begin
    bol:=true;
    for j:=1 to length(a) do if s[i+j-1]<>a[j] then begin
      bol:=false;
      break;
    end;
    if bol then begin
      mx1:=i;
      break;
    end;
  end;
  for i:=n-length(b)+1 downto 1 do begin
    bol:=true;
    for j:=1 to length(b) do if s[i+j-1]<>b[j] then begin
      bol:=false;
      break;
    end;
    if bol then begin
      mx2:=i;
      break;
    end;
  end;
  bol2:=(mx1<>0)and(mx2<>0)and(mx1+length(a)<=mx2);
  if bol1 and bol2 then writeln('both');
  if (not bol1) and bol2 then writeln('backward');
  if bol1 and (not bol2) then writeln('forward');
  if (not bol1) and (not bol2) then writeln('fantasy');
end.