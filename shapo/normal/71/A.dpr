uses Math,SysUtils;
var s :string;
    n,i,l:longint;
    res:array[1..100] of string;
begin
    readln(n);
    for i:= 1 to n do begin
        readln(s);
        if length(s)>10 then 
        res[i]:=s[1]+inttostr(length(s)-2)+s[length(s)]
        else res[i]:=s;
    end;
    for i:=1 to n do
        writeln(res[i]);
end.