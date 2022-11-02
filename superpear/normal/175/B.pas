const eps=1e-9;
var ming,nowm:array[0..1200] of string;
    num,nown,hash:array[0..1200] of longint;
    s:string;
    n,i,p,o,j,flag,sum:longint;
    q:extended;

function equal(a,b:extended):boolean;
  begin
    if abs(a-b)<=eps then exit(true) else exit(false);
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      p:=pos(' ',s);
      val(copy(s,p+1,length(s)-p),num[i]);
      ming[i]:=copy(s,1,p-1);
    end;
  o:=0;
  for i:=1 to n do
    begin
      flag:=-1;
      for j:=1 to i-1 do
        if ming[i]=ming[j] then
          begin
            flag:=hash[j];
            break;
          end;
      if flag=-1 then
        begin
          inc(o);
          nowm[o]:=ming[i];
          nown[o]:=num[i];
          hash[i]:=o;
        end
      else
        if num[i]>nown[flag] then nown[flag]:=num[i];
    end;
  writeln(o);
  for i:=1 to o do
    begin
      write(nowm[i],' ');
      sum:=0;
      for j:=1 to o do
        if nown[j]<=nown[i] then inc(sum);
      q:=sum/o;
      if equal(q,0.99) or (q>0.99) then writeln('pro')
      else
        if equal(q,0.9) or (q>0.9) then writeln('hardcore')
        else
          if equal(q,0.8) or (q>0.8) then writeln('average')
          else
            if equal(q,0.5) or (q>0.5) then writeln('random')
            else
              writeln('noob');
    end;
end.