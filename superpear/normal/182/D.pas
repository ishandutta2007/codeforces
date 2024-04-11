var s1,s2,s:ansistring;
    ls1,ls2,c,ans,i,flag,j,q:longint;

function gcd(a,b:longint):longint;
  begin
    if b=0 then exit(a) else exit(gcd(b,a mod b));
  end;

begin
  readln(s1);
  readln(s2);
  ls1:=length(s1);
  ls2:=length(s2);
  c:=gcd(ls1,ls2);
  ans:=0;
  for i:=1 to c do
    if c mod i=0 then
      begin
        s:=copy(s1,1,i);
        flag:=1;
        for j:=2 to ls1 div i do
          begin
            q:=(j-1)*i+1;
            if copy(s1,q,i)<>s then
              begin
                flag:=0;
                break;
              end;
          end;
        if flag=1 then
          begin
            for j:=1 to ls2 div i do
              begin
                q:=(j-1)*i+1;
                if copy(s2,q,i)<>s then
                  begin
                    flag:=0;
                    break;
                  end;
              end;
            if flag=1 then inc(ans);
          end;
      end;
  writeln(ans);
end.