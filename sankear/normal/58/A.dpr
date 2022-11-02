program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  state : integer;
  c : char;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  state := 1;
  while not eof do begin
    read(c);
    if (state = 1) and (c = 'h') then
      inc(state)
    else
      if (state = 2) and (c = 'e') then
        inc(state)
      else
        if (state = 3) and (c = 'l') then
          inc(state)
        else
          if (state = 4) and (c = 'l') then
            inc(state)
          else
            if (state = 5) and (c = 'o') then
              inc(state);
  end;
  if state > 5 then
    writeln('YES')
  else
    writeln('NO');
end.