var  
  n, x, y, i,k:longint;
  s:string;
     
begin
  read(n, x, y);
  n := n div 2;
  if ((x = n) or (x = n + 1)) and ((y = n) or (y = n + 1)) then
    write('NO')
  else
    write('YES');  
end.