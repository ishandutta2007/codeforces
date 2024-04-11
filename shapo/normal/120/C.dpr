program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n,k,i:longint;
    res:longint;
    a:array[1..1000]of longint;
    num:array[1..1000]of longint;
    used:array[1..1000]of boolean;
    fmx:longint;

function fmax:longint;
var i,res:longint;
begin
    res:=1;
    for i := 1 to n do begin
        if num[i] >= 3 then used[i]:=true;
        if (used[res]) or (not used[i] and (a[i]>=a[res]))
        then res:=i;
    end;
    fmax:=res;
end;

begin
    assign(input,'input.txt');
    assign(output,'output.txt');
    readln(n,k);
    for i:=1 to n do begin
        read(a[i]);
        num[i]:=0;
        used[i]:=false;
    end;
    res:=0;
    fmx:=fmax;
    while (a[fmx] >= k) and (num[fmx] <3) do begin
        a[fmx]:= a[fmx]-k;
        inc(num[fmx]);
        if num[fmx] > 3 then used[fmx] := true;
        fmx:=fmax;
    end;
    for i := 1 to n do
        res := res + a[i];
    writeln(res);
end.