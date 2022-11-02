program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

type
  tp = record
    l, num : integer;
  end;

var
  n, i, j, pow, ost : integer;
  t : tp;
  ans : array[0..1001, 0..1001] of integer;
  len : array[0..1001] of integer;
  p : array[0..1001] of tp;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(p[i].l);
  for i := 1 to n do begin
    len[i] := p[i].l;
    p[i].num := i;
  end;
  for i := 1 to n - 1 do
    for j := n downto i + 1 do
      if p[i].l > p[j].l then begin
        t := p[i];
        p[i] := p[j];
        p[j] := t;
      end;
  for i := 1 to p[1].l do
    ans[p[1].num, i] := 0;
  for i := 2 to n do
    if p[i].l = p[i - 1].l then begin
      ans[p[i].num] := ans[p[i - 1].num];
      ost := 1;
      for j := p[i].l downto 1 do begin
        ans[p[i].num, j] := ans[p[i].num, j] + ost;
        ost := ans[p[i].num, j] div 2;
        ans[p[i].num, j] := ans[p[i].num, j] mod 2;
      end;
      if ost > 0 then begin
        write('NO');
        halt(0);
      end;
    end
    else begin
      ans[p[i].num] := ans[p[i - 1].num];
      ost := 1;
      for j := p[i - 1].l downto 1 do begin
        ans[p[i].num, j] := ans[p[i].num, j] + ost;
        ost := ans[p[i].num, j] div 2;
        ans[p[i].num, j] := ans[p[i].num, j] mod 2;
      end;
      if ost > 0 then begin
        write('NO');
        halt(0);
      end;
      for j := p[i - 1].l + 1 to p[i].l do
        ans[p[i].num, j] := 0;
    end;
  writeln('YES');
  for i := 1 to n do begin
    for j := 1 to len[i] do
      write(ans[i, j]);
    writeln;
  end;
end.