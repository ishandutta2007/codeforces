program B;
var p,p1:array[1..20000] of int64;
    n,m,i,j,k:longint;
    x,d:int64;
    c:char;
    f:boolean;
begin
//  assign(input,'B.in');reset(input);
//  assign(output,'B.out');rewrite(output);
  readln(n,m);
  fillchar(p,sizeof(p),0);d:=0;
  for k:=1 to n do
    begin
      read(c);
      if c='a' then
        begin
          while c<>' ' do read(c);readln(x);
          if (x<0) or (x>m) then begin writeln('NULL');continue;end;
          for i:=1 to m-x+1 do
            begin
              f:=true;
              for j:=i to i+x-1 do f:=f and (p[j]=0);
              if f then
                begin
                  j:=i;break;
                end;
            end;
          if f then
            begin
              inc(d);for i:=j to j+x-1 do p[i]:=d;writeln(d);
            end else writeln('NULL');
        end else
      if c='e' then
        begin
          while c<>' ' do read(c);readln(x);
          if (x<=0) or (x>d) then begin writeln('ILLEGAL_ERASE_ARGUMENT');continue;end;
          j:=maxlongint;
          for i:=1 to m do
            if p[i]=x then
              begin
                j:=i;break;
              end;
          if j=maxlongint then writeln('ILLEGAL_ERASE_ARGUMENT') else
            for i:=1 to m do if p[i]=x then p[i]:=0;
        end else
        begin
          readln;
          fillchar(p1,sizeof(p1),0);
          j:=0;
          for i:=1 to m do
            if p[i]<>0 then
              begin
                inc(j);p1[j]:=p[i];
              end;
          for i:=1 to m do p[i]:=p1[i];
        end;
    end;
//  close(input);close(output);
end.