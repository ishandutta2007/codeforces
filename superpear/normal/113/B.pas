const big=314159;
      p=159328491233;
      p2=3214567;

var e:int64;
    s,s1,s2:ansistring;
    ls,ls1,ls2,i,ans,j:longint;
    ok1,ok2:array[0..3000] of longint;
    hash:array[0..10000000] of int64;

procedure push(x:int64);
  var c:longint;
  begin
    c:=x mod p2;
    while (hash[c]<>0) and (hash[c]<>x) do inc(c);
    if hash[c]=0 then
      begin
        inc(ans);
        hash[c]:=x;
      end;
  end;

begin
  readln(s);
  readln(s1);
  readln(s2);
  ls:=length(s);
  ls1:=length(s1);
  ls2:=length(s2);
  fillchar(ok1,sizeof(ok1),0);
  fillchar(ok2,sizeof(ok2),0);
  fillchar(hash,sizeof(hash),0);
  for i:=1 to ls-ls1+1 do
    if copy(s,i,ls1)=s1 then ok1[i]:=1;
  for i:=ls2 to ls do
    if copy(s,i-ls2+1,ls2)=s2 then ok2[i]:=1;
  ans:=0;
  for i:=1 to ls do
    if ok1[i]=1 then
      begin
        e:=0;
        for j:=i to ls do
          begin
            e:=(int64(e)*big+ord(s[j])) mod p;
            if (ok2[j]=1) and (j-i+1>=ls1) and (j-i+1>=ls2) then
              push(e);
          end;
      end;
  writeln(ans);
end.