Const a:array[1..6]of string=('jolteon', 'flareon', 'umbreon', 'leafeon', 'glaceon', 'sylveon' );
var n,l,r,i,j,k:Longint;
    b:array[1..6]of longint;
    s,t:string;
  begin
    readln(n);
    readln(s);
    if (n=6) then writeln('espeon') else
    if (n=8) then writeln('vaporeon') else
     begin
       for i:=1 to 7 do
        if s[i]<>'.' then
         begin
           for j:=1 to 6 do
            begin
              t:=a[j];
              if (t[i]<>s[i]) then b[j]:=1;
            end;
         end;
       for i:=1 to 6 do
        if b[i]=0 then writeln(a[i]);
     end;
  end.