var  
  i,k:longint;
  s:string;
     
begin
    readln(s);
    k := 0;
    for i:=2 to length(s) do
        if s[i] in ['A'..'Z'] then
            k:=k+1;
    if (k=length(s)-1) then
        begin
          if s[1] in ['A'..'Z'] then 
            s[1]:=chr(ord(s[1])+32) 
          else
            s[1]:=chr(ord(s[1])-32);
          for i:=2 to length(s) do 
            s[i]:=chr(ord(s[i])+32);
        end;
    write(s);
end.