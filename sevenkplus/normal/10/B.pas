program B;
var a:array[1..127,1..127] of boolean;
    n,m,k,i,j,p,x,y,t,ans,s,mid:longint;
begin
//  assign(input,'B.in');reset(input);
//  assign(output,'B.out');rewrite(output);
  readln(n,m);mid:=succ(m shr 1);
  fillchar(a,sizeof(a),false);
  for k:=1 to n do
    begin
      read(p);ans:=1000000000;x:=-1;
      for i:=1 to m do
        begin
          s:=0;t:=0;
          for j:=1 to m do
            begin
              if a[i,j] then
                begin
                  t:=0;s:=0;
                end else
                begin
                  inc(s);inc(t,abs(j-mid));
                end;
              if s>=p then
                begin
                  if t+abs(i-mid)*p<ans then
                    begin
                      ans:=t+abs(i-mid)*p;x:=i;y:=j;
                    end;
                  dec(t,abs(j-p+1-mid));
                end;
            end;
        end;
      if x=-1 then writeln(-1) else
        begin
          for j:=0 to p-1 do a[x,y-j]:=true;
          writeln(x,' ',y-p+1,' ',y);
        end;
    end;
//  close(input);close(output);
end.