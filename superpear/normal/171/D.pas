type tree=^pear;
     pear=record
            a:tree;
          end;

var n,i:longint;
    p:tree;
begin
  readln(n);
  if (n=3) or (n=5) then writeln(1) else
    begin
      if (n=4) or (n=1) then writeln(2) else writeln(3);
    end;
end.