program a2;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var a, b, c : string;
    a1, b1, c1, res : integer;

function ok(a, b : integer): boolean;
begin
    ok := (a - b + 3) mod 3 = 1;
end; 

begin
    readln(a);
    readln(b);
    readln(c);
    if a = 'rock' then a1 := 3;
    if a = 'paper' then a1 := 1;
    if a = 'scissors' then a1 := 2;
    if b = 'rock' then b1 := 3;
    if b = 'paper' then b1 := 1;
    if b = 'scissors' then b1 := 2;
    if c = 'rock' then c1 := 3;
    if c = 'paper' then c1 := 1;
    if c = 'scissors' then c1 := 2;
    res := 0;
    if ok(a1, b1) and ok(a1, c1) then res := 1;
    if ok(b1, a1) and ok(b1, c1) then res := 2;
    if ok(c1, a1) and ok(c1, b1) then res := 3;
    if res = 0 then writeln('?');
    if res = 1 then writeln('F');
    if res = 2 then writeln('M');
    if res = 3 then writeln('S');
end.program a2;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var a, b, c : string;
    a1, b1, c1, res : integer;

function ok(a, b : integer): boolean;
begin
    ok := (a - b + 3) mod 3 = 1;
end; 

begin
    readln(a);
    readln(b);
    readln(c);
    if a = 'rock' then a1 := 3;
    if a = 'paper' then a1 := 1;
    if a = 'scissors' then a1 := 2;
    if b = 'rock' then b1 := 3;
    if b = 'paper' then b1 := 1;
    if b = 'scissors' then b1 := 2;
    if c = 'rock' then c1 := 3;
    if c = 'paper' then c1 := 1;
    if c = 'scissors' then c1 := 2;
    res := 0;
    if ok(a1, b1) and ok(a1, c1) then res := 1;
    if ok(b1, a1) and ok(b1, c1) then res := 2;
    if ok(c1, a1) and ok(c1, b1) then res := 3;
    if res = 0 then writeln('?');
    if res = 1 then writeln('F');
    if res = 2 then writeln('M');
    if res = 3 then writeln('S');
end.