var a1,a2,a3,a4,i:longint;
    ans:ansistring;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a) else exit(b);
  end;

begin
  readln(a1,a2,a3,a4);
  if abs(a3-a4)>1 then
    begin
      writeln('-1');
      halt;
    end;
  if a3>a4 then
    begin
      ans:='';
      for i:=1 to a3 do
        ans:=ans+'47';
      a4:=a4-(a3-1);
      if (a1<a3) or (a2<a3) then
        begin
          writeln(-1);
          halt;
        end;
      a1:=a1-a3;
      a2:=a2-a3;
      for i:=1 to a1 do write(4);write(ans);for i:=1 to a2 do write(7);writeln;
    end;
  if a3<a4 then
    begin
      ans:='';
      for i:=1 to a4 do
        ans:=ans+'74';
      a3:=a3-(a4-1);
      if (a1<a4) or (a2<a4) then
        begin
          writeln(-1);
          halt;
        end;
      a1:=a1-a4;
      a2:=a2-a4;
      //for i:=1 to a2 do write(7);
      write(ans[1]);for i:=1 to a1 do write(4);
      delete(ans,1,1);
      delete(ans,length(ans),1);
      write(ans);
      for i:=1 to a2 do write(7);
      writeln(4);
    end;
  if a3=a4 then
    begin
      ans:='';
      for i:=1 to a3 do
        ans:=ans+'47';
      a4:=a4-(a3-1);
      if (a1<a3) or (a2<a3) then
        begin
          writeln(-1);
          halt;
        end;
      a1:=a1-a3;
      a2:=a2-a3;
      if a1>0 then
        begin
          dec(a1);
          for i:=1 to a1 do write(4);
          write(ans);
          for i:=1 to a2 do write(7);
          writeln(4);
        end
      else
        begin
          if a2<=0 then
            begin
              writeln(-1);
              halt;
            end;
          write(7);
          dec(a2);
          write(ans);
          for i:=1 to a2 do write(7);
          writeln;
        end;
    end;
end.