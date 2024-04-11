var s1,s2:array[1..100] of ansistring;
    st1,st2,t1,t2:array[char] of longint;
    l:array[1..100] of longint;
    u:array[1..100] of boolean;
    n,i,j,tt:longint;
    t:ansistring;
    cc:char;
function ff():longint;
  var i,s:longint;
      cc:char;
  begin
    fillchar(st1,sizeof(st1),0);
    fillchar(st2,sizeof(st2),0);s:=0;
    for i:=1 to n do
      if (l[i]<>0) and (s1[i][1]=s2[l[i]][1]) then inc(s);
    for i:=1 to n do
      if l[i]=0 then inc(st1[s1[i][1]]);
    for i:=1 to n do
      if not u[i] then inc(st2[s2[i][1]]);
    for cc:='A' to 'Z' do
      if st1[cc]<st2[cc] then inc(s,st1[cc]) else inc(s,st2[cc]);
    ff:=s;
  end;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(s1[i]);
    end;
  for i:=1 to n do
    for j:=i+1 to n do
      if s1[i]>s1[j] then
        begin
          t:=s1[i];s1[i]:=s1[j];s1[j]:=t;
        end;
  for i:=1 to n do
    begin
      readln(s2[i]);
    end;
  for i:=1 to n do
    for j:=i+1 to n do
      if s2[i]>s2[j] then
        begin
          t:=s2[i];s2[i]:=s2[j];s2[j]:=t;
        end;
  fillchar(l,sizeof(l),0);
  fillchar(u,sizeof(u),false);tt:=ff();
  for i:=1 to n do
    begin
      for j:=1 to n do
        if not u[j] then
          begin
            u[j]:=true;l[i]:=j;
            if ff()=tt then
              begin
                write(s1[i],' ',s2[j]);break;
              end else u[j]:=false;
          end;
      if i=n then writeln else write(', ');
    end;
end.