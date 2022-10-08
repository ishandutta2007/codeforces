//program C_;
label p1,p2;
var c:array[0..251,0..251] of char;
    s,t,k,l,x,n,m,i,j,p:longint;
procedure f(x,y:longint);
  begin
    if(x<1)or(x>n)or(y<1)or(y>m)or(c[x,y]<>'1')then exit;
    c[x,y]:='2';inc(s);
    f(x-1,y);f(x+1,y);f(x,y-1);f(x,y+1);f(x+1,y+1);f(x+1,y-1);f(x-1,y+1);f(x-1,y-1);
  end;
function nok(i,j:longint):boolean;
  begin
    nok:=(i<1)or(i>n)or(j<1)or(j>m)or(c[i,j]<>'2');
  end;
begin
//  assign(input,'C.in');reset(input);
//  assign(output,'C.out');rewrite(output);
  readln(t);
  for k:=1 to t do
    begin
      readln(n,m);
      fillchar(c,sizeof(c),0);
      for i:=1 to n do
        begin
          for j:=1 to m do read(c[i,j]);
          readln;
        end;
      x:=0;
      for i:=1 to n do
        for j:=1 to m do
          if c[i,j]='1' then
            begin
              s:=0;f(i,j);
              if(s mod 4=0)and(s div 4<=250)then
                begin
                  l:=s div 4;
                  for p:=0 to l do if nok(i+p,j) then goto p1;
                  for p:=0 to l do if nok(i,j+p) then goto p1;
                  for p:=0 to l do if nok(i+l,j+p) then goto p1;
                  for p:=0 to l do if nok(i+p,j+l) then goto p1;
                  inc(x);p1:
                  for p:=0 to l do if nok(i+p,j+p) then goto p2;
                  for p:=0 to l do if nok(i+p,j-p) then goto p2;
                  for p:=0 to l do if nok(i+l shl 1-p,j+p) then goto p2;
                  for p:=0 to l do if nok(i+l shl 1-p,j-p) then goto p2;
                  inc(x);p2:
                end;
            end;
      writeln(x);
    end;
//  close(input);close(output);
end.