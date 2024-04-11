var a:array[char,char] of longint;
    f,m,s:char;
begin
  fillchar(a,sizeof(a),0);
  a['r','s']:=1;a['p','r']:=1;a['s','p']:=1;
  readln(f);readln(m);readln(s);
  if (a[f,m]>0) and (a[f,s]>0) then writeln('F') else
  if (a[m,f]>0) and (a[m,s]>0) then writeln('M') else
  if (a[s,f]>0) and (a[s,m]>0) then writeln('S') else writeln('?');
end.