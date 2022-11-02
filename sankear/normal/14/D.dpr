program codeforces;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  maxn = 200;

type
  tv = record
    u : array of integer;
    k : integer;
  end;

var
  n, i, j, a, b, ans : integer;
  used, del : array[1..maxn] of boolean;
  v : array[1..maxn] of tv;

function dfs(i, k : integer) : integer;
var j, d, max2 : integer;
begin
  used[i] := true;
  result := 0;
  max2 := 0;
  for j := 1 to v[i].k do
    if (not del[v[i].u[j]]) and (not used[v[i].u[j]]) then begin
      d := dfs(v[i].u[j], k) + 1;
      if d > result then begin
        max2 := result;
        result := d;
      end
      else
        if d > max2 then
          max2 := d;
    end;
  if result = 0 then
    result := 1;
  if (i = k) and (max2 > 0) then
    result := result + max2 - 1;
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  randomize;
  read(n);
  for i := 1 to n - 1 do begin
    read(a, b);
    setlength(v[a].u, v[a].k + 2);
    inc(v[a].k);
    v[a].u[v[a].k] := b;
    setlength(v[b].u, v[b].k + 2);
    inc(v[b].k);
    v[b].u[v[b].k] := a;
  end;
  ans := 0;
  for i := 1 to n - 1 do
    for j := i + 1 to n do begin
      del[i] := true;
      del[j] := true;
      fillchar(used, sizeof(used), 0);
      a := dfs(i, i) - 1;
      b := dfs(j, j) - 1;
      del[i] := false;
      del[j] := false;
      if a * b > ans then
        ans := a * b;
    end;
  write(ans);
end.