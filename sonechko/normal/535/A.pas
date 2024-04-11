const a:array[0..20] of string =
('zero','one','two','three','four','five','six','seven','eight','nine','ten',
'eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen',
'eighteen','nineteen','twenty');
const b:array[2..9]of string=('twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety');
var n:longint;
  begin
    read(n);
    if n<=20 then begin writeln(a[n]); halt; end;
    if n mod 10=0 then writeln(b[n div 10]) else
    writeln(b[n div 10],'-',a[n mod 10]);
  end.