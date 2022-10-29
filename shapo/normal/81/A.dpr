var stack:array[0..2000000]of char;
    num,i:longint;
    s:string;
begin
    readln(s);
    num:=0;
    for i:=1 to length(s) do begin
        if (num=0)or(s[i]<>stack[num]) then begin
            inc(num);
            stack[num]:=s[i];
        end
        else dec(num);
    end;
    for i:= 1 to num do
        write(stack[i]);
end.