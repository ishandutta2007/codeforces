var a,sg,sgsum,hash:array[0..100000] of longint;
    n,ans,i,j,k,o,ak,sg1:longint;
    a1:int64;

begin
  readln(n);
  sg[1]:=0;
  sg[2]:=0;
  sgsum[0]:=0;
  sgsum[1]:=0;
  sgsum[2]:=0;
  ans:=maxlongint;
  for i:=3 to n do
    begin
      for j:=2 to trunc(sqrt(i*2)) do
        if (i*2) mod j=0 then
          begin
            k:=j;
            a1:=i-int64(k)*(k-1) div 2;
            if (a1>0) and (a1 mod k=0) then
              begin
                a1:=a1 div k;
                ak:=a1+(k-1);
                sg1:=sgsum[ak] xor sgsum[a1-1];
                hash[sg1]:=i;
                if (i=n) and (sg1=0) then
                  if j<ans then ans:=j;
              end;
          end;
      for j:=0 to 100 do
        if hash[j]<>i then
          begin
            sg[i]:=j;
            break;
          end;
      sgsum[i]:=sgsum[i-1] xor sg[i];
    end;
  if ans=maxlongint then ans:=-1;
  writeln(ans);
end.