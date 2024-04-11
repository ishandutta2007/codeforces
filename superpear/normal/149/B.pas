var s,s1,s2:string;
    c:char;
    p,ls1,ls2,ans,i,j,k,e1,e2:longint;
    a:array[0..1000] of longint;
begin
  readln(s);
  p:=pos(':',s);
  s1:=copy(s,1,p-1);
  ls1:=length(s1);
  s2:=copy(s,p+1,length(s)-p);
  ls2:=length(s2);
  ans:=0;
  for i:=2 to 200 do
    begin
      e1:=0;
      for j:=1 to ls1 do
        begin
          c:=s1[j];
          if (c>='0') and (c<='9') then k:=ord(c)-48 else k:=ord(c)-55;
          if k>=i then
            begin
              e1:=maxlongint;
              break;
            end;
          e1:=e1*i+k;
          if e1>10000 then break;
        end;
      if e1<=23 then
        begin
          e2:=0;
          for j:=1 to ls2 do
            begin
              c:=s2[j];
              if (c>='0') and (c<='9') then k:=ord(c)-48 else k:=ord(c)-55;
              if k>=i then
                begin
                  e2:=maxlongint;
                  break;
                end;
              e2:=e2*i+k;
              if e2>10000 then break;
            end;
          if e2<=59 then
            begin
              inc(ans);
              a[ans]:=i;
            end;
        end;
    end;
  if ans=0 then writeln(0) else
    if ans>80 then writeln(-1) else
      begin
        for i:=1 to ans-1 do write(a[i],' ');writeln(a[ans]);
      end;
end.