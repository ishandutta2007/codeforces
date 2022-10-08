program B_;
var a,b,d1,d2:array[0..1000,0..1000] of longint;
    b1,b2:array[1..1000,1..1000] of boolean;
    n,i,j,x,y,p:longint;
    s:ansistring;
    f:boolean;
begin
//  assign(input,'B.in');reset(input);
//  assign(output,'B.out');rewrite(output);
  readln(n);f:=true;
  for i:=1 to n do
    for j:=1 to n do
      begin
        read(a[i,j]);
        f:=f and (a[i,j]<>0);
      end;
  if f then
    begin
      for i:=1 to n do
        for j:=1 to n do
          begin
            p:=a[i,j];b[i,j]:=0;
            while not odd(p) do
              begin
                inc(b[i,j]);p:=p shr 1;
              end;
          end;
      fillchar(d1,sizeof(d1),0);
      for i:=1 to n do
        begin
          d1[0,i]:=2000;d1[i,0]:=2000;
        end;
      d1[0,1]:=0;
      for i:=1 to n do
        for j:=1 to n do
          if d1[i-1,j]<d1[i,j-1] then
            begin
              d1[i,j]:=d1[i-1,j]+b[i,j];b1[i,j]:=true;
            end else
            begin
              d1[i,j]:=d1[i,j-1]+b[i,j];b1[i,j]:=false;
            end;
      for i:=1 to n do
        for j:=1 to n do
          begin
            p:=a[i,j];b[i,j]:=0;
            while p mod 5=0 do
              begin
                inc(b[i,j]);p:=p div 5;
              end;
          end;
      fillchar(d2,sizeof(d2),0);
      for i:=1 to n do
        begin
          d2[0,i]:=2000;d2[i,0]:=2000;
        end;
      d2[0,1]:=0;
      for i:=1 to n do
        for j:=1 to n do
          if d2[i-1,j]<d2[i,j-1] then
            begin
              d2[i,j]:=d2[i-1,j]+b[i,j];b2[i,j]:=true;
            end else
            begin
              d2[i,j]:=d2[i,j-1]+b[i,j];b2[i,j]:=false;
            end;
      s:='';
      if d1[n,n]<d2[n,n] then
        begin
          x:=n;y:=n;writeln(d1[n,n]);
          while (x<>1) or (y<>1) do
            if b1[x,y] then
              begin
                dec(x);s:='D'+s;
              end else
              begin
                dec(y);s:='R'+s;
              end;
          writeln(s);
        end else
        begin
          x:=n;y:=n;writeln(d2[n,n]);
          while (x<>1) or (y<>1) do
            if b2[x,y] then
              begin
                dec(x);s:='D'+s;
              end else
              begin
                dec(y);s:='R'+s;
              end;
          writeln(s);
        end;
    end else
    begin
      for i:=1 to n do
        for j:=1 to n do if a[i,j]=0 then b[i,j]:=10000 else
          begin
            p:=a[i,j];b[i,j]:=0;
            while not odd(p) do
              begin
                inc(b[i,j]);p:=p shr 1;
              end;
          end;
      fillchar(d1,sizeof(d1),0);
      for i:=1 to n do
        begin
          d1[0,i]:=2000;d1[i,0]:=2000;
        end;
      d1[0,1]:=0;
      for i:=1 to n do
        for j:=1 to n do
          if d1[i-1,j]<d1[i,j-1] then
            begin
              d1[i,j]:=d1[i-1,j]+b[i,j];b1[i,j]:=true;
            end else
            begin
              d1[i,j]:=d1[i,j-1]+b[i,j];b1[i,j]:=false;
            end;
      for i:=1 to n do
        for j:=1 to n do if a[i,j]=0 then b[i,j]:=10000 else
          begin
            p:=a[i,j];b[i,j]:=0;
            while p mod 5=0 do
              begin
                inc(b[i,j]);p:=p div 5;
              end;
          end;
      fillchar(d2,sizeof(d2),0);
      for i:=1 to n do
        begin
          d2[0,i]:=2000;d2[i,0]:=2000;
        end;
      d2[0,1]:=0;
      for i:=1 to n do
        for j:=1 to n do
          if d2[i-1,j]<d2[i,j-1] then
            begin
              d2[i,j]:=d2[i-1,j]+b[i,j];b2[i,j]:=true;
            end else
            begin
              d2[i,j]:=d2[i,j-1]+b[i,j];b2[i,j]:=false;
            end;
      s:='';
      if d1[n,n]<d2[n,n] then
        if d1[n,n]=0 then
          begin
            x:=n;y:=n;writeln(d1[n,n]);
            while (x<>1) or (y<>1) do
              if b1[x,y] then
                begin
                  dec(x);s:='D'+s;
                end else
                begin
                  dec(y);s:='R'+s;
                end;
            writeln(s);
          end else
          begin
            for i:=1 to n do
              for j:=1 to n do
                if a[i,j]=0 then
                  begin
                    x:=i;y:=j;
                  end;
            writeln(1);
            for i:=1 to x-1 do write('D');
            for j:=1 to y-1 do write('R');
            for i:=x to n-1 do write('D');
            for j:=y to n-1 do write('R');
          end else
        if d2[n,n]=0 then
          begin
            x:=n;y:=n;writeln(d2[n,n]);
            while (x<>1) or (y<>1) do
              if b2[x,y] then
                begin
                  dec(x);s:='D'+s;
                end else
                begin
                  dec(y);s:='R'+s;
                end;
            writeln(s);
          end else
          begin
            for i:=1 to n do
              for j:=1 to n do
                if a[i,j]=0 then
                  begin
                    x:=i;y:=j;
                  end;
            writeln(1);
            for i:=1 to x-1 do write('D');
            for j:=1 to y-1 do write('R');
            for i:=x to n-1 do write('D');
            for j:=y to n-1 do write('R');
          end;
    end;
//  close(input);close(output);
end.