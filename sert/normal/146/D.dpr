var s, k: string;
    n, i, l, r: longint;
    fail: boolean;
    u74, u47, u4, u7, a4, a7, a47, a74: longint;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(a4, a7, a47, a74);
  if (a4 = 1) and (a7 = 2) and (a47 = 1) and (a74 = 1) then begin write(747); halt; end;
  if (a4 = 1) and (a7 = 1) and (a47 = 1) and (a74 = 1) then begin write(-1); halt; end;
  if (a4 = a7) and (a7 = a47) and (a47 = a74) then begin write(-1); halt; end;
  if abs(a47 - a74) > 1 then begin write('-1'); halt; end;
  if (a4 < a47) or (a4 < a74) or (a7 < a47) or (a7 < a74) then begin write('-1'); halt; end;
  if (a4 = 1) and (a47 = 1) and (a74 = 1) then begin write(74);
  for i := 1 to a7 - 1 do write('7'); halt; end;
  u47 := 0;
  u74 := 0;
  u4 := 0;
  u7 := 0;

  if a47 = a74 then
  begin
    if (a4 < a7) and (a47 = a4) then
    begin
      write('7');
      for i := 1 to a4 do write('47');
      for i := 1 to a7 - a4 - 1 do write('7');
      halt;
    end;
    for i := 1 to a4 - a47 do write('4');
    for i := 1 to a47 - 1 do
      write('74');
    for i := 1 to a7 - a47 + 1 do write('7');
      write('4');
    halt;
  end;

  if a47 > a74 then
  begin
    for i := 1 to a4 - a47 + 1 do write('4');
    for i := 1 to a47 - 1 do
      write('74');
    for i := 1 to a7 - a47 + 1 do write('7');
    halt;
  end;

  if a74 > a47 then
  begin
    write('7');
    for i := 1 to a4 - a74 + 1 do write('4');
    for i := 1 to a74 - 2 do write('74');
    for i := 1 to a7 - a74 + 1 do write('7');
    write('4');
  end;


end.