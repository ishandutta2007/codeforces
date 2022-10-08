const max=int64(100000000)*int64(100000000);
type exp=
       record
         l:longint;
         p:array[1..4] of int64;
         q:array[1..3] of char;
       end;
var a:exp;
function ff(a:exp):int64;
  var b:exp;
      i,j,k,l:longint;
      x,t:int64;
  begin
    if a.l=1 then
      begin
        ff:=a.p[1];exit;
      end;
    x:=max;
    for i:=1 to a.l-1 do
      for j:=i+1 to a.l do
        for k:=1 to 1 do
          begin
            b.l:=0;
            for l:=1 to a.l do
              if (l<>i) and (l<>j) then
                begin
                  inc(b.l);b.p[b.l]:=a.p[l];
                end;
            b.l:=0;
            for l:=1 to a.l-1 do
              if l<>k then
                begin
                  inc(b.l);b.q[b.l]:=a.q[l];
                end;
            b.l:=a.l-1;
            if a.q[k]='*' then b.p[b.l]:=a.p[i]*a.p[j] else b.p[b.l]:=a.p[i]+a.p[j];
            t:=ff(b);
            if x>t then x:=t;
          end;
    ff:=x;
  end;
begin
  a.l:=4;
  readln(a.p[1],a.p[2],a.p[3],a.p[4]);
  read(a.q[1],a.q[2],a.q[2],a.q[3],a.q[3]);
  writeln(ff(a));
end.