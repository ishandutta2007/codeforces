program stpni;

{$APPTYPE CONSOLE}

function nod(var a, b: int64):int64;
var k: int64;
begin
  k := a mod b;
  if a mod b = 0 then nod := b else nod := nod(b, k);
end;

var a, b, q: int64;
    aa, bb: int64;
begin
//reset(input,'input.txt');
//rewrite(output,'output.txt');
read(a, b);
q := nod(a, b);
a := a div q;
b := b div q;
if a < b then
begin
aa := (a * (a + 1)) div 2;
bb := a * b - aa;
end
else
begin
  bb := (b * (b + 1)) div 2;
  aa := a * b - bb;
end;
if aa < bb then write('Dasha');
if aa > bb then write('Masha');
if aa = bb then write('Equal');
end.