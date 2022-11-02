var m,n,i,j,c,ans,now:longint;
    ch:char;
    a:array[0..200,0..200] of longint;
    left,right,ok:array[0..200] of longint;

function max(a,b:longint):longint;
  begin
    if a>b then exit(a) else exit(b);
  end;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a) else exit(b);
  end;

begin
  readln(m,n);
  for i:=1 to m do
    begin
      for j:=1 to n do
        begin
          read(ch);
          if ch='W' then a[i,j]:=1 else a[i,j]:=0;
        end;
      readln;
    end;
  ans:=-1;
  for i:=1 to m do
    begin
      left[i]:=1;
      right[i]:=n;
      ok[i]:=0;
      for j:=1 to n do
        if a[i,j]=1 then
          begin
            ok[i]:=1;
            left[i]:=j;
            break;
          end;
      for j:=n downto 1 do
        if a[i,j]=1 then
          begin
            right[i]:=j;
            break;
          end;
    end;
  for i:=m-1 downto 1 do
    if ok[i]=0 then
      begin
        left[i]:=n;
        right[i]:=1;
        //left[i]:=left[i+1];
        //right[i]:=right[i+1];
      end;
  while (m>1) and (ok[m]=0) do dec(m);
  now:=1;
  c:=1;
  left[m+1]:=n;
  right[m+1]:=1;
  for i:=1 to m do
    begin
      inc(ans);
      if (ok[i]=0) and (ok[i+1]=0) then
        continue;
      if i mod 2=0 then
        begin
          c:=min(min(left[i],left[i+1]),c);
          ans:=ans+abs(c-now);
          now:=c;
        end
      else
        begin
          c:=max(max(right[i],right[i+1]),c);
          ans:=ans+abs(c-now);
          now:=c;
        end;
    end;
  writeln(ans);
end.