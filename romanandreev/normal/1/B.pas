program Zb;
{$O-}
{$APPTYPE CONSOLE}
{$MODE DELPHI}
uses
  SysUtils,
  Math;

var n,i,j,k,x1,x2,l,kl,mm:longint;
    s,ss:string;
    bol,bb:boolean;
    c1,c2,c3,c4,c5:char;
    aa:array[0..1500000]of string;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  kl:=0;
   for c1:='A' to 'Z' do begin
            inc(kl);
            aa[kl]:=c1;
          end;
   for c1:='A' to 'Z' do
    for c2:='A' to 'Z' do begin
            inc(kl);
            aa[kl]:=c1+c2;
          end;
   for c1:='A' to 'Z' do
    for c2:='A' to 'Z' do
      for c3:='A' to 'Z' do begin
            inc(kl);
            aa[kl]:=c1+c2+c3;
          end;
   for c1:='A' to 'Z' do
    for c2:='A' to 'Z' do
      for c3:='A' to 'Z' do
        for c4:='A' to 'Z' do begin
            inc(kl);
            aa[kl]:=c1+c2+c3+c4;
          end;
  for c1:='A' to 'B' do
    for c2:='A' to 'Z' do
      for c3:='A' to 'Z' do
        for c4:='A' to 'Z' do
          for c5:='A' to 'Z' do begin
            inc(kl);
            aa[kl]:=c1+c2+c3+c4+c5;
          end;

  readln(n);
  for k:=1 to n do begin
    readln(s);
    l:=length(s);
    bol:=false;
    if s[1]='R' then
    for i:=3 to l-1 do if s[i]='C' then begin
      bb:=true;
      for j:=2 to i-1 do if s[j] in ['A'..'Z'] then begin
        bb:=false;
      end;
      for j:=i+1 to l do if s[j] in ['A'..'Z'] then begin
        bb:=false;
      end;
      if bb then begin
        x1:=strtoint(copy(s,2,i-2));
        delete(s,1,i);
        x2:=strtoint(s);
        write(aa[x2]);
        writeln(x1);
        bol:=true;
        break;
      end;
    end;
    if not bol then begin
      for i:=1 to l do if s[i] in ['0'..'9'] then begin
        write('R');
        write(copy(s,i,l-i+1));
        ss:=copy(s,1,i-1);
        x1:=1;
        x2:=2000000;
        while x1<x2 do begin
          mm:=(x1+x2+1) div 2;
          if (length(aa[mm])>length(ss))or((length(aa[mm])=length(ss))and(aa[mm]>ss)) then x2:=mm-1
                      else x1:=mm;
        end;
        writeln('C',x1);
        break;
      end;
    end;
  end;
end.