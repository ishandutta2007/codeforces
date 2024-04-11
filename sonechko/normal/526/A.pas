var n,m,i,j,k,ans,l,r:longint;
    s:ansistring;
    a:array[1..100]of longint;
    b:array[1..100]of longint;
  begin
    readln(n);
    readln(s);
    for i:=1 to n do
     s:=s+'.';

    for i:=1 to n do
     begin
       for j:=1 to n  do
        if (s[i]='*') and (s[i+j]='*') and (s[i+j*2]='*') and
         (s[i+j*3]='*') and (s[i+j*4]='*') then begin writeln('yes'); halt; end;
     end;
    writeln('no');
  end.