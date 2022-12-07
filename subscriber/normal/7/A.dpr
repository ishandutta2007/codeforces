var
 ans,i,j:longint;
 v,h:array[1..8]of byte;
 s:array[1..8]of string;
begin
 for i:=1 to 8 do readln(s[i]);
 for i:=1 to 8 do h[i]:=1;
 for i:=1 to 8 do v[i]:=1;
 for i:=1 to 8 do for j:=1 to 8 do if s[i,j]='W' then h[i]:=0;
 for i:=1 to 8 do for j:=1 to 8 do if s[j,i]='W' then v[i]:=0;
 if h[1]+h[2]+h[3]+h[4]+h[5]+h[6]+h[7]+h[8]=8 then
 begin
  writeln(8);
  halt;
 end;
 ans:=0;
 for i:=1 to 8 do inc(ans,v[i]);
 for i:=1 to 8 do inc(ans,h[i]);
 writeln(ans);
end.