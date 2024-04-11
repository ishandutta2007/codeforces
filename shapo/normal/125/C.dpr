program task;

{$APPTYPE CONSOLE}
{$O-}

uses
  Math,
  SysUtils;

var n,i,j,k,maxl,mc1,mc2:longint;
    used1,used2:array[1..10000]of longint;
    curs:array[1..2000]of longint;

begin
    fillchar(used1,sizeof(used1),0);
    fillchar(used2,sizeof(used2),0);
    fillchar(curs,sizeof(curs),0);
    readln(n);
    i:=10000;
    while ((i-1)*i > 2*n) do dec(i);
    k:=i;
    writeln(k);
    maxl:=k-1;
    mc1:=1;
    mc2:=mc1+1;
    for i:=1 to k*(k-1) div 2 do begin
        inc(curs[mc1]);
        inc(curs[mc2]);
        used1[i]:=mc1;
        used2[i]:=mc2;
        inc(mc2);
        if curs[mc1]=maxl then begin
            inc(mc1);
            mc2:=mc1+1;
        end;
    end;
    for i:=1 to k do begin
        for j:= 1 to (k-1)*k div 2 do
            if (used1[j]=i) or (used2[j]=i) then write(j,' ');
        writeln;
    end;
    halt(0);
end.