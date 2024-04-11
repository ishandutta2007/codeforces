var s:string;
    num:array[1..256]of int64;
    i:longint;
    res:int64;
begin
readln(s);
for i:=1 to 256 do num[i]:=0;
for i:=1 to length(s) do inc(num[ord(s[i])]);
res:=0;
for i:=1 to 256 do 
    res:=res+(num[i]*num[i]);
writeln(res);
end.