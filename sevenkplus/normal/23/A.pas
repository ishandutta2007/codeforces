var s:string;
    n,i,j,k,m,f,l:longint;
begin
  readln(s);l:=0;
  n:=length(s);
  for i:=1 to n do
    if n-i+1>l then
      for j:=l+1 to n-i+1 do
        begin
          f:=0;
          for k:=i+1 to n-l+1 do
            if copy(s,k,j)=copy(s,i,j) then begin f:=1;break;end;
          if f=1 then if j>l then l:=j;
        end;
  writeln(l);
end.