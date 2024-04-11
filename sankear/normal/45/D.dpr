program solution;

{$APPTYPE CONSOLE}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

type
  tp = record
    l, r, num : integer;
  end;
  tr = record
    val : byte;
    num : integer;
  end;

var
  n, maxv, i, j : integer;
  t : tp;
  res : tr;
  p : array[0..101] of tp;
  rmqval : array[0..33554432] of byte;
  rmqnum : array[0..33554432] of integer;
  ans : array[0..101] of integer;

function more(var a, b : tp) : boolean;
begin
  result := (a.r > b.r) or ((a.r = b.r) and (a.l > b.l));
end;

function less(v1, v2 : integer) : boolean;
begin
  result := (rmqval[v1] < rmqval[v2]) or ((rmqval[v1] = rmqval[v2]) and (rmqnum[v1] < rmqnum[v2]));
end;

procedure add(v : integer; val : byte);
begin
  v := v + maxv - 1;
  rmqval[v] := val;
  rmqnum[v] := v - maxv + 1;
  while v > 1 do begin
    v := v div 2;
    if less(v * 2, v * 2 + 1) then begin
      rmqval[v] := rmqval[v * 2];
      rmqnum[v] := rmqnum[v * 2];
    end
    else begin
      rmqval[v] := rmqval[v * 2 + 1];
      rmqnum[v] := rmqnum[v * 2 + 1];
    end;
  end;
end;

function rmin(l, r : integer) : tr;
begin
  rmqval[0] := 1;
  rmqnum[0] := 10000001;
  l := l + maxv - 1;
  r := r + maxv - 1;
  while l <= r do begin
    if less(l, 0) then begin
      rmqval[0] := rmqval[l];
      rmqnum[0] := rmqnum[l];
    end;
    l := (l + 1) div 2;
    if less(r, 0) then begin
      rmqval[0] := rmqval[r];
      rmqnum[0] := rmqnum[r];
    end;
    r := (r - 1) div 2;
  end;
  result.val := rmqval[0];
  result.num := rmqnum[0];
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(p[i].l, p[i].r);
  for i := 1 to n do
    p[i].num := i;
  for i := 1 to n - 1 do
    for j := n downto i + 1 do
      if more(p[i], p[j]) then begin
        t := p[i];
        p[i] := p[j];
        p[j] := t;
      end;
  maxv := 1;
  while maxv < 10000000 do
    maxv := maxv * 2;
  for i := 1 to 10000000 do begin
    rmqval[i + maxv - 1] := 0;
    rmqnum[i + maxv - 1] := i;
  end;
  for i := 10000001 to maxv do begin
    rmqval[i + maxv - 1] := 1;
    rmqnum[i + maxv - 1] := i;
  end;
  for i := maxv - 1 downto 1 do
    if less(i * 2, i * 2 + 1) then begin
      rmqval[i] := rmqval[i * 2];
      rmqnum[i] := rmqnum[i * 2];
    end
    else begin
      rmqval[i] := rmqval[i * 2 + 1];
      rmqnum[i] := rmqnum[i * 2 + 1];
    end;
  for i := 1 to n do begin
    res := rmin(p[i].l, p[i].r);
    add(res.num, 1);
    ans[p[i].num] := res.num;
  end;
  for i := 1 to n do
    write(ans[i], ' ');
end.