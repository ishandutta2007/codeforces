var s:string;
    i:longint;
begin
    readln(s);i:=pos('//',s);
    while i<>0 do
        begin
            delete(s,i,1);
            i:=pos('//',s);
        end;
    if(s<>'/')and(s[length(s)]='/')then delete(s,length(s),1);
    writeln(s);
end.