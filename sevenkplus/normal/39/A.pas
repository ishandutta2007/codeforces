program foo;
 var
  a: longint;
  n: longint;
  s: ansistring;
  c: array[1..1000]of longint;
  f: array[1..1000]of boolean;
 procedure init;
  var
   tmp: longint;
   err: integer;
   sub: ansistring;
  begin
   readln(a);
   readln(s);
   insert('+', s, 1);
   n:= 0;
   while length(s) > 0 do
    begin
     if pos('a++', s) = 0 then
      tmp:= pos('++a', s) + 2
     else
     if pos('++a', s) = 0 then
      tmp:= pos('a++', s) + 2
     else
     if pos('a++', s) < pos('++a', s) then
      tmp:= pos('a++', s) + 2
     else
      tmp:= pos('++a', s) + 2;
     sub:= copy(s, 1, tmp);
     delete(s, 1, tmp);
     inc(n);
     f[n]:= pos('++a', sub) > 0;
     if sub[1] = '-' then
      c[n]:= - 1
     else
      c[n]:= 1;
     while pos('+', sub) > 0 do
      delete(sub, pos('+', sub), 1);
     while pos('-', sub) > 0 do
      delete(sub, pos('-', sub), 1);
     while pos('a', sub) > 0 do
      delete(sub, pos('a', sub), 1);
     while pos('*', sub) > 0 do
      delete(sub, pos('*', sub), 1);
     if (sub <> '') then
      begin
       val(sub, tmp, err);     
       c[n]:= c[n] * tmp;
      end;
    end;
  end;
 procedure sort;
  var
   i, j, k, tmpc: longint;
   tmpf         : boolean;
  begin
   for i:= 1 to n do
    begin
     k:= i;
     for j:= i + 1 to n do
      if c[j] < c[k] then
       k:= j;
     tmpc:= c[i];
     c[i]:= c[k];
     c[k]:= tmpc;
     tmpf:= f[i];
     f[i]:= f[k];
     f[k]:= tmpf;
    end;
  end;
 procedure main;
  var
   i, s: longint;
  begin
   s:= 0;
   for i:= 1 to n do
    if f[i] then
     begin
      inc(a);
      inc(s, c[i] * a);
     end
    else
     begin
      inc(s, c[i] * a);
      inc(a);
     end;
   writeln(s);
  end;
 begin
  init;
  sort;
  main;
 end.