program gen;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type int=longint;
const md=239017;
var s:array[0..6000000]of char;
    n,i:int;
    ans:int64;
    stp,hs,hs2,kk:array[0..6000000]of int64;
begin
//  reset(input,'input.txt');
//  rewrite(output,'output.txt');
  n:=0;
  while not seekeof do begin
    inc(n);
    read(s[n]);
  end;
  stp[0]:=1;
  for i:=1 to n do stp[i]:=stp[i-1]*md;
  hs[n+1]:=0;
  for i:=n downto 1 do
    hs[i]:=md*hs[i+1]+ord(s[i])*ord(s[i]);
  hs2[0]:=0;
  for i:=1 to n do
    hs2[i]:=md*hs2[i-1]+ord(s[i])*ord(s[i]);
  ans:=0;
  for i:=0 to n do kk[i]:=0;
  for i:=1 to n do if hs2[i]=hs[1]-hs[i+1]*stp[i] then begin
    kk[i]:=kk[i shr 1]+1;
    inc(ans,kk[i]);
  end;
  writeln(ans);
end.