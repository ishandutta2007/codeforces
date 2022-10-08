program A_;
{$M 16777216}
const l28=1 shl 28;
var a,b:array[0..9,0..9] of longint;
    i,j,s,m:longint;
    c:char;
procedure fi(k,d:longint);
  var i,j,x,y:longint;
      f:boolean;
  begin
    if d>=m then exit;
    if k=0 then
      begin
        m:=d;exit;
      end;
    for x:=1 to 8 do
      begin
        for y:=1 to 8 do if (a[x,y]=0) and (b[x,y]=0) then break;
        if (a[x,y]=0) and (b[x,y]=0) then break;
      end;
    //Case 1
    f:=true;
    for i:=1 to 8 do f:=f and (a[x,i]=0);
    if f then
      begin
        for i:=1 to 8 do
          begin
            if b[x,i]=0 then dec(k);
            inc(b[x,i]);
          end;
        fi(k,d+1);
        for i:=1 to 8 do
          begin
            if b[x,i]=1 then inc(k);
            dec(b[x,i]);
          end;
      end;
    //Case 2
    f:=true;
    for i:=1 to 8 do f:=f and (a[i,y]=0);
    if f then
      begin
        for i:=1 to 8 do
          begin
            if b[i,y]=0 then dec(k);
            inc(b[i,y]);
          end;
        fi(k,d+1);
        for i:=1 to 8 do
          begin
            if b[i,y]=1 then inc(k);
            dec(b[i,y]);
          end;
      end;
  end;
begin
//  assign(input,'A.in');reset(input);
//  assign(output,'A.out');rewrite(output);
  s:=0;
  for i:=0 to 9 do
    for j:=0 to 9 do a[i,j]:=l28;
  for i:=1 to 8 do
    begin
      for j:=1 to 8 do
        begin
          read(c);
          if c='B' then
            begin
              inc(s);a[i,j]:=0;
            end;
        end;
      readln;
    end;
  fillchar(b,sizeof(b),0);
  m:=l28;fi(s,0);writeln(m);
//  close(input);close(output);
end.