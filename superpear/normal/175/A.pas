const max=1000000;
var s,s1,s2,s3:string;
    n,i,j,c1,c2,c3,ans:longint;
begin
  readln(s);
  n:=length(s);
  ans:=-1;
  for i:=2 to n-1 do
    for j:=i+1 to n do
      begin
        s1:=copy(s,1,i-1);
        s2:=copy(s,i,j-i);
        s3:=copy(s,j,n-j+1);
        if ((s1[1]='0') and (s1<>'0'))
        or ((s2[1]='0') and (s2<>'0'))
        or ((s3[1]='0') and (s3<>'0'))
          then continue;
        if length(s1)>=8 then continue;
        if length(s2)>=8 then continue;
        if length(s3)>=8 then continue;
        val(s1,c1);
        val(s2,c2);
        val(s3,c3);
        if (c1<=max) and (c2<=max) and (c3<=max) then
          if c1+c2+c3>ans then ans:=c1+c2+c3;
      end;
  writeln(ans);
end.