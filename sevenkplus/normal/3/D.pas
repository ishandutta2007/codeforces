program D_;
var p,w:array[1..50005] of longint;
    h,n,i,c,x,y:longint;
    d:int64;
    s:ansistring;
    f:boolean;
procedure add(k,l:longint);
  var d,f:longint;
  begin
    inc(h);d:=h;
    while d<>1 do
      begin
        f:=d shr 1;
        if p[f]>k then
          begin
            w[d]:=w[f];p[d]:=p[f];d:=f;
          end else break;
      end;
    p[d]:=k;w[d]:=l;
  end;
procedure del(k:longint);
  var d,cl,l:longint;
  begin
    d:=k;k:=p[h];l:=w[h];dec(h);
    while d shl 1<=h do
      begin
        cl:=d shl 1;
        if (cl<h) and (p[cl+1]<p[cl]) then inc(cl);
        if p[cl]<k then
          begin
            w[d]:=w[cl];p[d]:=p[cl];d:=cl;
          end else break;
      end;
    p[d]:=k;w[d]:=l;
  end;
begin
//  assign(input,'D.in');reset(input);
//  assign(output,'D.out');rewrite(output);
  readln(s);n:=length(s);c:=0;d:=0;h:=0;f:=true;
  for i:=1 to n do
    begin
      if s[i]='(' then inc(c) else
      if s[i]=')' then dec(c) else
        begin
          readln(x,y);s[i]:=')';
          inc(d,y);dec(c);add(x-y,i);
        end;
      while c<0 do
        begin
          if h=0 then begin writeln(-1);halt;end;
          inc(d,p[1]);s[w[1]]:='(';del(1);inc(c,2);
        end;
    end;
  if not f or (c<>0) then writeln(-1) else
    begin
      writeln(d);writeln(s);
    end;
//  close(input);close(output);
end.