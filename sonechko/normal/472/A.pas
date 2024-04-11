var n,i:longint;
 function prost(n:longint):boolean;
  var i:longint;
   begin
     for i:=2 to round(sqrt(n)) do
      if n mod i=0 then begin prost:=true; exit; end;
     prost:=false;
   end;
  begin
    read(n);
    for i:=2 to n div 2 do
     if (prost(i)) and (prost(n-i)) then begin writeln(i,' ',n-i); halt; end;

  end.