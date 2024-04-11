program Project2;

{$APPTYPE CONSOLE}

uses
  Math, SysUtils;

var s : string;
    i, ch, nch : integer;

function up(s : string) : string;
var i : integer;
    res : string;
begin
    res := '';
    for i := 1 to length(s) do
        if ord(s[i]) >= 97 then res := res + chr(ord(s[i]) - 32) else res := res + s[i];
    up := res;
end;

function low(s : string) : string;
var i : integer;
    res : string;
begin
    res := '';
    for i := 1 to length(s) do
        if ord(s[i]) <= 90 then res := res + chr(ord(s[i]) + 32) else res := res + s[i];
    low := res;
end;

begin
    readln(s);
    ch := 0;
    nch := 0;
    for i := 1 to length(s) do
        if ord(s[i]) <= 90 then inc(ch) else inc(nch);
    if ch > nch then writeln(up(s)) else writeln(low(s));
end.