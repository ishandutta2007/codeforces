var s,ss:ansistring;
    n,i,c1,c2,o0,o1,o2,e0,e1,o:longint;

function max(a,b:longint):longint;
  begin
    if a>b then exit(a) else exit(b);
  end;

function doit(s:ansistring):string;
  var i,k1,k2:longint;
  begin
    for i:=n downto 1 do
      if s[i]='0' then
        begin
          k1:=i;
          break;
        end;
    for i:=n downto 1 do
      if s[i]='1' then
        begin
          k2:=i;
          break;
        end;
    if k1<k2 then exit('01') else exit('10');
  end;

begin
  readln(s);
  n:=length(s);
  c1:=(n-2)-(n-2) div 2;
  c2:=(n-2) div 2;
  o0:=0;
  o1:=0;
  o2:=0;
  for i:=1 to n do
    begin
      if s[i]='0' then inc(o0);
      if s[i]='1' then inc(o1);
      if s[i]='?' then inc(o2);
    end;
  if (o0+o2-c2)-max(o1-c1,0)>=2 then writeln('00');
  e0:=n div 2-o0;
  e1:=n-n div 2-o1;
  if (e0>=0) and (e1>=0) then
    begin
      ss:=s;
      o:=0;
      for i:=1 to n do
        if ss[i]='?' then
          begin
            inc(o);
            if o<=e0 then ss[i]:='0' else ss[i]:='1';
          end;
      if doit(ss)='01' then writeln('01');
      ss:=s;
      o:=0;
      for i:=1 to n do
        if ss[i]='?' then
          begin
            inc(o);
            if o<=e1 then ss[i]:='1' else ss[i]:='0';
          end;
      if doit(ss)='10' then writeln('10');
    end;
  if (o1+o2-c1)-max(o0-c2,0)>=2 then writeln('11');
end.