program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, m, k, a, b, i : integer;
  fl : boolean;
  del : array[0..101] of boolean;
  used, use, p, pp, first, lst : array[0..101] of integer;
  go, next : array[0..30001] of integer;

procedure add(a, b : integer);
begin
  inc(k);
  go[k] := b;
  next[k] := first[a];
  first[a] := k;
end;

procedure dfs2(a, b : integer);
var i : integer;
begin
  use[a] := 1;
  i := first[a];
  while i > 0 do begin
    if go[i] <> pp[a] then begin
    if del[go[i]] then begin
      if (a <> lst[b]) or ((go[i] <> lst[b - 1]) and (go[i] <> lst[b + 1])) then
        fl := false;
    end
    else
      if use[go[i]] = 0 then begin
        pp[go[i]] := a;
        dfs2(go[i], b);
      end
      else
        if use[go[i]] = 1 then
          fl := false;
    end;
    i := next[i];
  end;
  use[a] := 2;
end;

procedure dfs1(a : integer);
var k, i, j : integer;
begin
  used[a] := 1;
  i := first[a];
  while i > 0 do begin
    if go[i] <> p[a] then begin
      if used[go[i]] = 0 then begin
        p[go[i]] := a;
        dfs1(go[i]);
      end
      else
        if used[go[i]] = 1 then begin
          k := 0;
          j := a;
          while true do begin
            inc(k);
            lst[k] := j;
            del[j] := true;
            if j = go[i] then
              break;
            j := p[j];
          end;
          lst[0] := lst[k];
          lst[k + 1] := lst[1];
          fl := true;
          for j := 1 to k do
            dfs2(lst[j], j);
          for j := 1 to n do
            if use[j] = 0 then
              fl := false;
          if fl then begin
            writeln('FHTAGN!');
            halt;
          end;
          writeln('NO');
          halt;
        end;
    end;
    i := next[i];
  end;
  used[a] := 2;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  k := 0;
  for i := 1 to m do begin
    read(a, b);
    add(a, b);
    add(b, a);
  end;
  dfs1(1);
  writeln('NO');
end.