var sc,st:ansistring;
    s:array[0..100000] of ansistring;
    ls,n,i,o:longint;
    a:array[0..100000] of longint;

function male(s:ansistring):boolean;
  var ls:longint;
  begin
    ls:=length(s);
    if (ls>=4) and (copy(s,ls-3,4)='lios') then exit(true);
    if (ls>=3) and (copy(s,ls-2,3)='etr') then exit(true);
    if (ls>=6) and (copy(s,ls-5,6)='initis') then exit(true);
    exit(false);
  end;

function female(s:ansistring):boolean;
  var ls:longint;
  begin
    ls:=length(s);
    if (ls>=5) and (copy(s,ls-4,5)='liala') then exit(true);
    if (ls>=4) and (copy(s,ls-3,4)='etra') then exit(true);
    if (ls>=6) and (copy(s,ls-5,6)='inites') then exit(true);
    exit(false);
  end;

function kind(s:ansistring):longint;
  var ls:longint;
  begin
    ls:=length(s);
    if (ls>=4) and (copy(s,ls-3,4)='lios') then exit(1);
    if (ls>=5) and (copy(s,ls-4,5)='liala') then exit(1);
    if (ls>=3) and (copy(s,ls-2,3)='etr') then exit(2);
    if (ls>=4) and (copy(s,ls-3,4)='etra') then exit(2);
    if (ls>=6) and (copy(s,ls-5,6)='initis') then exit(3);
    if (ls>=6) and (copy(s,ls-5,6)='inites') then exit(3);
    exit(0);
  end;

begin
  readln(sc);
  sc:=sc+' ';
  ls:=length(sc);
  n:=0;
  st:='';
  for i:=1 to ls do
    if sc[i]=' ' then
      begin
        inc(n);
        s[n]:=st;
        st:='';
      end
    else
      st:=st+sc[i];
  for i:=1 to n do
    if (not male(s[i])) and (not female(s[i])) then
      begin
        writeln('NO');
        halt;
      end;
  if n=1 then
    begin
      writeln('YES');
      halt;
    end;
  for i:=1 to n do
    if male(s[i]) then a[i]:=1 else a[i]:=2;
  for i:=2 to n do
    if a[i]<>a[i-1] then
      begin
        writeln('NO');
        halt;
      end;
  fillchar(a,sizeof(a),0);
  for i:=1 to n do a[i]:=kind(s[i]);
  o:=1;
  while (o<=n) and (a[o]=1) do inc(o);
  if (o>n) or (a[o]<>2) then
    begin
      writeln('NO');
      halt;
    end;
  for i:=o+1 to n do
    if a[i]<>3 then
      begin
        writeln('NO');
        halt;
      end;
  writeln('YES');
end.