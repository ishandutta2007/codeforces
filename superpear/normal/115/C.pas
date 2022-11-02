const p=1000003;

var m,n,i,j,ans,ok,flag,c1,c2,c3,c4:longint;
    a:array[0..500000] of char;

begin
  readln(m,n);
  for i:=1 to m do
    begin
      for j:=1 to n do
        read(a[(i-1)*n+j]);
      readln;
    end;
  ans:=1;
  for i:=1 to m do
    begin
      flag:=1;
      ok:=1;
      c1:=0;c2:=0;c3:=0;c4:=0;
      for j:=1 to n do
        if a[(i-1)*n+j]<>'.' then
          begin
            flag:=0;
            if (a[(i-1)*n+j]='1') or (a[(i-1)*n+j]='2') then
              if j mod 2=1 then c1:=1 else c2:=1;
            if (a[(i-1)*n+j]='3') or (a[(i-1)*n+j]='4') then
              if j mod 2=1 then c3:=1 else c4:=1;
          end;
      if flag=1 then ans:=ans*2 mod p;
      if ((c1=1) and (c3=1)) or ((c2=1) and (c4=1))
      or ((c1=1) and (c2=1)) or ((c3=1) and (c4=1)) then
        ans:=0;
    end;
  for j:=1 to n do
    begin
      flag:=1;
      ok:=1;
      c1:=0;c2:=0;c3:=0;c4:=0;
      for i:=1 to m do
        if a[(i-1)*n+j]<>'.' then
          begin
            flag:=0;
            if (a[(i-1)*n+j]='1') or (a[(i-1)*n+j]='4') then
              if i mod 2=1 then c1:=1 else c2:=1;
            if (a[(i-1)*n+j]='2') or (a[(i-1)*n+j]='3') then
              if i mod 2=1 then c3:=1 else c4:=1;
          end;
      if flag=1 then ans:=ans*2 mod p;
      if ((c1=1) and (c3=1)) or ((c2=1) and (c4=1))
      or ((c1=1) and (c2=1)) or ((c3=1) and (c4=1)) then
        ans:=0;
    end;
  writeln(ans);
end.