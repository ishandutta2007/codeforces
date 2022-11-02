const big=1000000000;

var a,b,mo,i,c,j:longint;
    st:string;

begin
  readln(a,b,mo);
  for i:=1 to a do
    begin
      c:=int64(i)*big mod mo;
      if c>0 then c:=mo-c;
      if c>b then
        begin
          write('1 ');
          str(i,st);
          for j:=1 to 9-length(st) do write('0');
          writeln(st);
          halt;
        end;
      if i>mo then break;
    end;
  writeln('2');
end.