var a,b,m,r0,i:longint;
    hash,r:array[0..1000000] of longint;
begin
  readln(a,b,m,r0);
  r[0]:=r0;
  fillchar(hash,sizeof(hash),0);
  for i:=1 to 1000000 do
    begin
      r[i]:=(int64(a)*r[i-1]+b) mod m;
      if hash[r[i]]<>0 then
        begin
          writeln(i-hash[r[i]]);
          break;
        end;
      hash[r[i]]:=i;
    end;
end.