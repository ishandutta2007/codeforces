program C96;

const md = 1000003;

var s: string;
    i: longint;
    st, k, n, p, t: longint;
begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(s);
  st := 1;
  k := 0;
  for i := length(s) downto 1 do
  begin
    if (s[i] = '>') then p := 8;
    if (s[i] = '<') then p := 9;
    if (s[i] = '+') then p := 10;
    if (s[i] = '-') then p := 11;
    if (s[i] = '.') then p := 12;
    if (s[i] = ',') then p := 13;
    if (s[i] = '[') then p := 14;
    if (s[i] = ']') then p := 15;
    t := (st * p) mod md;
    k := (k + t) mod md;
    st := (st * 16) mod md;
  end;
  write(k);
end.