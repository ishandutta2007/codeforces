var i,ls,max,maxk,sum,j:longint;
    s:ansistring;
    a,ans:array[0..10000] of longint;

function prime(s:longint):boolean;
  var i:longint;
  begin
    for i:=2 to trunc(sqrt(s)) do
      if s mod i=0 then exit(false);
    exit(true);
  end;

begin
  readln(s);
  ls:=length(s);
  fillchar(a,sizeof(a),0);
  for i:=1 to ls do
    inc(a[ord(s[i])-96]);
  max:=0;
  maxk:=0;
  for i:=1 to 26 do
    if a[i]>max then
      begin
        max:=a[i];
        maxk:=i;
      end;
  sum:=0;
  for i:=2 to ls do
    if (i*2<=ls) or not(prime(i)) then inc(sum);
  if max<sum then
    writeln('NO')
  else
    begin
      fillchar(ans,sizeof(ans),0);
      for i:=2 to ls do
        if (i*2<=ls) or not(prime(i)) then
          begin
            ans[i]:=maxk;
            dec(a[maxk]);
          end;
      for i:=1 to ls do
        if ans[i]=0 then
          for j:=1 to 26 do
            if a[j]>0 then
              begin
                ans[i]:=j;
                dec(a[j]);
                break;
              end;
      writeln('YES');
      for i:=1 to ls do write(chr(ans[i]+96));writeln;
    end;
end.