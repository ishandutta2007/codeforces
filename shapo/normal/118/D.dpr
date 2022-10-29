program task;

{$APPTYPE CONSOLE}
{$O-,R+,S+,Q+,I+}

uses
  Math,
  SysUtils;

const maxp = 100*1000*1000;

var n1, n2, k1, k2, i, j, k : longint;
    res : longint;
    a : array[0..200, 0..101, 1..2, 1..11] of longint;

begin
    readln(n1, n2, k1, k2);
    fillchar(a, sizeof(a), 0);
    a[1, 1, 1, 1] := 1;
    a[1, 0, 2, 1] := 1;
    for i := 1 to n1 + n2 - 1 do begin
        for j := 0 to n1 do begin
            if j <> 0 then begin
                for k := 1 to min(n1,k1) do begin
                    a[i + 1, j + 1, 1, k + 1] := (a[i + 1, j + 1, 1, k + 1]
                    + a[i, j, 1, k]) mod maxp;
                    a[i + 1, j, 2, 1] := (a[i + 1, j, 2, 1] + a[i, j, 1, k])mod maxp;
                end;
            end;
            if (i - j <> 0) then begin
                for k := 1 to min(n2,k2) do begin
                    a[i + 1, j, 2, k + 1] := (a[i+1, j, 2, k+1]+a[i, j, 2, k])mod maxp;
                    a[i+1, j+1, 1, 1]:=(a[i+1, j+1,1, 1]+a[i, j, 2,k])mod maxp;
                end;
            end;
        end;
    end;
    res := 0;
    for i:=1 to min(n1,k1) do
        res := (res+a[n1+n2,n1,1,i])mod maxp;
    for i:=1 to min(n2,k2) do
        res:=(res+a[n1+n2,n1,2,i])mod maxp;
    writeln(res);
    halt(0);
end.