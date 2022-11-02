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
  n, i : integer;
  c : char;
  s : string;
  r : array['A'..'Z', 'A'..'Z'] of boolean;
  used : array['A'..'Z'] of integer;
  num : array[0..4] of char;

procedure dfs(v : char);
var i : char;
begin
  used[v] := 1;
  for i := 'A' to 'Z' do
    if r[v, i] then begin
      if used[i] = 0 then
        dfs(i)
      else
        if used[i] = 1 then begin
          writeln('Impossible');
          halt(0);
        end;
    end;
  used[v] := 2;
  inc(n);
  num[n] := v;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  for i := 1 to 3 do begin
    readln(s);
    if s[2] = '>' then
      r[s[3], s[1]] := true
    else
      r[s[1], s[3]] := true;
  end;
  n := 0;
  for c := 'A' to 'C' do
    if used[c] = 0 then
      dfs(c);
  for i := n downto 1 do
    write(num[i]);
  writeln;
end.