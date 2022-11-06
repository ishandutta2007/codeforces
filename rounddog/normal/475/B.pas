
program dirty_2;

var
    n,m:longint;
    s1,s2:string;
    f:boolean;

begin
  readln(n,m);
  readln(s1);readln(s2);
  f:=true;
  if (s1[1]='<') and (s2[1]='^') then f:=false;
  if (s1[1]='>') and (s2[m]='^') then f:=false;
  if (s1[n]='<') and (s2[1]='v') then f:=false;
  if (s1[n]='>') and (s2[m]='v') then f:=false;
  if f then writeln('YES') else writeln('NO');readln;
end.