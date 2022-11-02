const maxn=100000;

var f:array[0..maxn] of longint;
    tt,gb,n,i,j,ans:longint;

procedure doit1(s:longint);
  begin
    ans:=1;
  end;

procedure doit2(s:longint);
  var i,c:longint;
  begin
    c:=s mod 10;
    for i:=0 to 9 do
      if f[c*10+i]=0 then inc(ans);
  end;

procedure doit3(s:longint);
  var a1,a2,c1,c2,c3,e:longint;
  begin
    a1:=(s div 10) mod 10;
    a2:=s mod 10;
    for c1:=0 to 9 do
      for c2:=0 to 9 do
        for c3:=0 to 9 do
          begin
            e:=f[a1*100+c1*10+c2]+f[a2*100+c2*10+c3];
            if e=0 then inc(ans);
          end;
  end;

procedure doit4(s:longint);
  var a1,a2,a3,c1,c2,c3,o1,o2,o3:longint;
  begin
    a1:=(s div 100) mod 10;
    a2:=(s div 10) mod 10;
    a3:=s mod 10;
    for c1:=0 to 9 do
      for c2:=0 to 9 do
        for c3:=0 to 9 do
          begin
            o1:=0;
            for i:=0 to 9 do
              if f[a1*1000+i*100+c1*10+c2]=0 then inc(o1);
            o2:=0;
            for i:=0 to 9 do
              if f[a2*1000+c1*100+i*10+c3]=0 then inc(o2);
            o3:=0;
            for i:=0 to 9 do
              if f[a3*1000+c2*100+c3*10+i]=0 then inc(o3);
            ans:=ans+o1*o2*o3;
          end;
  end;

procedure doit5(s:longint);
  var a1,a2,a3,a4,c1,c2,c3,c4,c5,c6,o1,o2,o3,o4,i:longint;
  begin
    a1:=(s div 1000) mod 10;
    a2:=(s div 100) mod 10;
    a3:=(s div 10) mod 10;
    a4:=s mod 10;
    for c1:=0 to 9 do
      for c2:=0 to 9 do
        for c3:=0 to 9 do
          for c4:=0 to 9 do
            for c5:=0 to 9 do
              for c6:=0 to 9 do
                begin
                  o1:=0;
                  for i:=0 to 9 do
                    if f[a1*10000+i*1000+c1*100+c2*10+c3]=0 then inc(o1);
                  if o1=0 then continue;
                  o2:=0;
                  for i:=0 to 9 do
                    if f[a2*10000+c1*1000+i*100+c4*10+c5]=0 then inc(o2);
                  if o2=0 then continue;
                  o3:=0;
                  for i:=0 to 9 do
                    if f[a3*10000+c2*1000+c4*100+i*10+c6]=0 then inc(o3);
                  if o3=0 then continue;
                  o4:=0;
                  for i:=0 to 9 do
                    if f[a4*10000+c3*1000+c5*100+c6*10+i]=0 then inc(o4);
                  ans:=ans+o1*o2*o3*o4;
                end;
  end;

begin
  fillchar(f,sizeof(f),0);
  f[0]:=1;
  f[1]:=1;
  for i:=2 to maxn do
    if f[i]=0 then
      for j:=i to maxn div i do
        f[i*j]:=1;

  readln(tt);
  for gb:=1 to tt do
    begin
      readln(n);
      ans:=0;
      if n<10 then doit1(n)
      else
        if n<100 then doit2(n)
        else
          if n<1000 then doit3(n)
          else
            if n<10000 then doit4(n)
            else
              if n>=10000 then doit5(n);
      writeln(ans);
    end;
end.