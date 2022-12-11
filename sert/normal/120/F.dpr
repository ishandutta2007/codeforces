Type Tdmas = array[1..200] of integer;
Type Mt = record
num: integer;
len: integer;
end;

var a: Tdmas;
    u: array[1..200, 1..200] of integer;
    r, n, k, p, sum, q, w: integer;

function bfs (i: integer): Mt;
var q: Tdmas;
    u1, u2, j, max, s: integer;
    dl, use: Tdmas;
begin
  fillchar(q, sizeof(q), 0);
  fillchar(use, sizeof(use), 0);
  fillchar(dl, sizeof(dl), 0);
  u1 := 1;
  u2 := 1;
  q[1] := i;
  use[q[1]] := 1;
  s := 1;
  max := 0;
  while u1 <= u2 do
  begin
    for j := 1 to n do
      if (u[q[u1], j] = 1) and (use[j] = 0) then
      begin
        inc (u2);
        q[u2] := j;
        use[j] := 1;
        dl[j] := dl[q[u1]] + 1;
        if dl[j] > max then                               
        begin
          max := dl[j];
          s := j;
        end;                                                          
      end;
    inc (u1);
  end;
  bfs.num := s;
  bfs.len := max;
end;

begin
reset(input,'input.txt');
rewrite(output,'output.txt');
read(k);
sum := 0;
for p := 1 to k do
begin
  for w := 1 to 200 do for q := 1 to 200 do u[w, q] := 0;
  read(n);
  for w := 1 to n - 1 do
  begin
    read(r, q);
    u[r, q] := 1;
    u[q, r] := 1;
  end;
  q := bfs(1).num;
  sum := sum + bfs(q).len;
end;
write(sum);
end.