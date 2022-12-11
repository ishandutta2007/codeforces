program vkc;

{$APPTYPE CONSOLE}

type M = record
  s: string[200];
  u: integer;
end;

var a: array[0..10000] of M;
    j, cd, i, n, kol, h: integer;
    s, k: string;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  readln(n);
  a[0].s := '/';
  a[0].u := -1;
  cd := 0;
  kol := 0;
  for i := 1 to n do
  begin
    readln(s);
    if s = 'pwd' then
    begin
      k := '';
      h := cd;
      while h <> 0 do
      begin
        k := a[h].s + k;
        h := a[h].u;
      end;
      k := '/' + k;
      writeln(k);
    end
    else
    begin
      delete(s, 1, 3);
      if s[1] = '/' then begin delete(s, 1, 1); cd := 0; end;
      s := s + '/';
      k := '';
      j := 1;
      while j <= length(s) do
      begin
        k := '';
        while s[j] <> '/' do
        begin
          k := k + s[j];
          inc(j);
        end;
        inc(j);
        if k = '..' then
          cd := a[cd].u
        else
        begin
          inc(kol);
          a[kol].s := k + '/';
          a[kol].u := cd;
          cd := kol;
        end;
      end;
    end;
  end;

end.