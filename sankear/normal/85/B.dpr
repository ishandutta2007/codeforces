program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  inf = round(1e18);

type
  tr = record
    val : int64;
    pos : integer;
  end;

var
  n, k1, k2, k3, t1, t2, t3, maxv, i : integer;
  ans : int64;
  f1, f2, f3 : boolean;
  cur, res : tr;
  s : array[0..100001] of integer;
  a, b : array[0..100001] of int64;
  rmq, r1, r2, r3 : array[0..280001] of tr;

function less(var a, b : tr) : boolean;
begin
  result := a.val < b.val;
end;

procedure calc(a : integer);
begin
  if less(rmq[a * 2], rmq[a * 2 + 1]) then
    rmq[a] := rmq[a * 2]
  else
    rmq[a] := rmq[a * 2 + 1];
end;

procedure calc1(a : integer);
begin
  if less(r1[a * 2], r1[a * 2 + 1]) then
    r1[a] := r1[a * 2]
  else
    r1[a] := r1[a * 2 + 1];
end;

procedure calc2(a : integer);
begin
  if less(r2[a * 2], r2[a * 2 + 1]) then
    r2[a] := r2[a * 2]
  else
    r2[a] := r2[a * 2 + 1];
end;

procedure calc3(a : integer);
begin
  if less(r3[a * 2], r3[a * 2 + 1]) then
    r3[a] := r3[a * 2]
  else
    r3[a] := r3[a * 2 + 1];
end;

procedure add(a : integer; b : int64);
begin
  a := a + maxv - 1;
  rmq[a].val := b;
  while a > 1 do begin
    a := a div 2;
    calc(a);
  end;
end;

procedure add1(a : integer; b : int64);
begin
  a := a + maxv - 1;
  r1[a].val := b;
  while a > 1 do begin
    a := a div 2;
    calc1(a);
  end;
end;

procedure add2(a : integer; b : int64);
begin
  a := a + maxv - 1;
  r2[a].val := b;
  while a > 1 do begin
    a := a div 2;
    calc2(a);
  end;
end;

procedure add3(a : integer; b : int64);
begin
  a := a + maxv - 1;
  r3[a].val := b;
  while a > 1 do begin
    a := a div 2;
    calc3(a);
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(k1, k2, k3, t1, t2, t3, n);
  for i := 1 to n do
    read(a[i]);
  for i := 1 to n do
    b[i] := a[i];
  f1 := false;
  if k1 >= n then
    f1 := true;
  f2 := false;
  if k2 >= n then
    f2 := true;
  f3 := false;
  if k3 >= n then
    f3 := true;
  maxv := 1;
  while maxv < n do
    maxv := maxv * 2;
  if not f1 then begin
    for i := 1 to k1 do begin
      r1[i + maxv - 1].val := 0;
      r1[i + maxv - 1].pos := i;
    end;
    for i := k1 + 1 to maxv do begin
      r1[i + maxv - 1].val := inf;
      r1[i + maxv - 1].pos := i;
    end;
    for i := maxv - 1 downto 1 do
      calc1(i);
  end;
  if not f2 then begin
    for i := 1 to k2 do begin
      r2[i + maxv - 1].val := 0;
      r2[i + maxv - 1].pos := i;
    end;
    for i := k2 + 1 to maxv do begin
      r2[i + maxv - 1].val := inf;
      r2[i + maxv - 1].pos := i;
    end;
    for i := maxv - 1 downto 1 do
      calc2(i);
  end;
  if not f3 then begin
    for i := 1 to k3 do begin
      r3[i + maxv - 1].val := 0;
      r3[i + maxv - 1].pos := i;
    end;
    for i := k3 + 1 to maxv do begin
      r3[i + maxv - 1].val := inf;
      r3[i + maxv - 1].pos := i;
    end;
    for i := maxv - 1 downto 1 do
      calc3(i);
  end;
  for i := 1 to n do
    s[i] := 1;
  for i := 1 to n do begin
    rmq[i + maxv - 1].val := a[i];
    rmq[i + maxv - 1].pos := i;
  end;
  for i := n + 1 to maxv do begin
    rmq[i + maxv - 1].val := inf;
    rmq[i + maxv - 1].pos := i;
  end;
  for i := maxv - 1 downto 1 do
    calc(i);
  while true do begin
    cur := rmq[1];
    if cur.val = inf then
      break;
    if s[cur.pos] = 1 then begin
      if f1 then begin
        a[cur.pos] := a[cur.pos] + t1;
        add(cur.pos, a[cur.pos]);
      end
      else begin
        res := r1[1];
        a[cur.pos] := max(a[cur.pos], res.val) + t1;
        add1(res.pos, a[cur.pos]);
        add(cur.pos, a[cur.pos]);
      end;
      inc(s[cur.pos]);
    end
    else
      if s[cur.pos] = 2 then begin
        if f2 then begin
          a[cur.pos] := a[cur.pos] + t2;
          add(cur.pos, a[cur.pos]);
        end
        else begin
          res := r2[1];
          a[cur.pos] := max(a[cur.pos], res.val) + t2;
          add2(res.pos, a[cur.pos]);
          add(cur.pos, a[cur.pos]);
        end;
        inc(s[cur.pos]);
      end
      else begin
        if f3 then begin
          a[cur.pos] := a[cur.pos] + t3;
          add(cur.pos, inf);
        end
        else begin
          res := r3[1];
          a[cur.pos] := max(a[cur.pos], res.val) + t3;
          add3(res.pos, a[cur.pos]);
          add(cur.pos, inf);
        end;
      end;
  end;
  ans := 0;
  for i := 1 to n do
    ans := max(ans, a[i] - b[i]);
  writeln(ans);
end.