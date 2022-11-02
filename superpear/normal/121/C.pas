var b:array[0..10] of longint;
    a:array[0..100000] of longint;
    i,o,s,j,n,k,c,e,sum,sc:longint;
    fact:array[0..15] of int64;
    use,ans:array[0..20] of longint;

function lucky(s:longint):boolean;
  begin
    while s>0 do
      begin
        if (s mod 10<>4) and (s mod 10<>7) then exit(false);
        s:=s div 10;
      end;
    exit(true);
  end;

begin
  o:=0;
  for i:=1 to 9 do
    begin
      fillchar(b,sizeof(b),0);
      while b[0]=0 do
        begin
          s:=0;
          for j:=1 to i do
            if b[j]=0 then s:=s*10+4 else s:=s*10+7;
          inc(o);
          a[o]:=s;
          j:=i;
          while b[j]=1 do
            begin
              b[j]:=0;
              dec(j);
            end;
          inc(b[j]);
        end;
    end;
  //for i:=1 to o do writeln(a[i]);
  readln(n,k);
  fact[0]:=1;
  for i:=1 to 15 do
    fact[i]:=int64(fact[i-1])*i;
  if n<=15 then
    begin
      if k>fact[n] then
        begin
          writeln(-1);
          halt;
        end;
      dec(k);
      fillchar(use,sizeof(use),0);
      for i:=1 to n do
        begin
          c:=k div fact[n-i]+1;
          k:=k mod fact[n-i];
          e:=0;
          for j:=1 to n do
            if use[j]=0 then
              begin
                inc(e);
                if e=c then
                  begin
                    ans[i]:=j;
                    use[j]:=1;
                    break;
                  end;
              end;
        end;
      //for i:=1 to n do write(ans[i],' ');writeln;
      sum:=0;
      for i:=1 to n do
        if lucky(i) and lucky(ans[i]) then inc(sum);
      writeln(sum);
    end
  else
    begin
      sc:=n-15;
      n:=15;
      dec(k);
      fillchar(use,sizeof(use),0);
      for i:=1 to n do
        begin
          c:=k div fact[n-i]+1;
          k:=k mod fact[n-i];
          e:=0;
          for j:=1 to n do
            if use[j]=0 then
              begin
                inc(e);
                if e=c then
                  begin
                    ans[i]:=j;
                    use[j]:=1;
                    break;
                  end;
              end;
        end;
      for i:=1 to n do ans[i]:=ans[i]+sc;
      //for i:=1 to sc do write(i,' ');for i:=1 to n do write(ans[i],' ');writeln;
      sum:=0;
      for i:=1 to o do
        if a[i]<=sc then inc(sum);
      for i:=1 to n do
        if lucky(i+sc) and lucky(ans[i]) then inc(sum);
      writeln(sum);
    end;
end.