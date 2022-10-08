program A_;
var s:array[1..1000] of string;
    a,c,d:array[1..1000] of longint;
    n,i,j,p,m,k:longint;
    ch:char;
    f:boolean;
begin
//  assign(input,'A.in');reset(input);
//  assign(output,'A.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      s[i]:='';read(ch);
      while ch<>' ' do
        begin
          s[i]:=s[i]+ch;read(ch);
        end;
      a[i]:=0;read(ch);
      if ch='-' then begin f:=false;read(ch);end else f:=true;
      while not eoln do
        begin
          a[i]:=a[i]*10+ord(ch)-ord('0');read(ch);
        end;
      a[i]:=a[i]*10+ord(ch)-ord('0');
      if not f then a[i]:=-a[i];
      readln;
    end;
  fillchar(c,sizeof(c),0);
  for i:=1 to n do
    for j:=1 to i do
      if s[i]=s[j] then
        begin
          inc(c[j],a[i]);break;
        end;
  m:=0;p:=0;
  for i:=1 to n do
    if c[i]>m then
      begin
        m:=c[i];p:=1;k:=i;
      end else
    if c[i]=m then inc(p);
  if p=1 then writeln(s[k]) else
    begin
      fillchar(d,sizeof(d),0);
      for i:=1 to n do
        for j:=1 to i do
          if s[i]=s[j] then
            begin
              inc(d[j],a[i]);
              if (c[j]=m) and (d[j]>=m) then
                begin
                  writeln(s[j]);
//                  close(input);close(output);
                  halt;
                end;
              break;
            end;
    end;
//  close(input);close(output);
end.