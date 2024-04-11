var d,f,px,py:array[1..51] of longint;
    x,y:array[1..2501] of longint;
    a:array[1..51,1..51] of boolean;
    n,m,i,j,k,t:longint;
    g:boolean;
function fa(x:longint):longint;
  begin
    if f[x]=x then fa:=x else
      begin
        f[x]:=fa(f[x]);fa:=f[x];
      end;
  end;
function con:boolean;
  var i,fx:longint;
  begin
    fx:=fa(1);con:=true;
    for i:=2 to n do if fa(i)<>fx then con:=false;
  end;
begin
//  assign(input,'E.in');reset(input);
//  assign(output,'E.out');rewrite(output);
  read(n,m);
  for i:=1 to m do
    begin
      read(x[i],y[i]);
      if x[i]>y[i] then
        begin
          t:=x[i];x[i]:=y[i];y[i]:=t;
        end;
    end;
  if m>n then
    begin
      writeln('NO');
      //close(input);close(output);
      halt;
    end;
  for i:=1 to m do
    if (y[i]>n) or (x[i]<1) then
      begin
        writeln('NO');
        //close(input);close(output);
        halt;
      end;
  if n=1 then
    if m=1 then
      begin
        writeln('YES');writeln(0);
        //close(input);close(output);
        halt;
      end else
    if m=0 then
      begin
        writeln('YES');writeln(1);writeln('1 1');
        //close(input);close(output);
        halt;
      end else
      begin
        writeln('NO');
        //close(input);close(output);
        halt;
      end;
  fillchar(d,sizeof(d),0);
  for i:=1 to n do f[i]:=i;
  for i:=1 to m do
    begin
      inc(d[x[i]]);inc(d[y[i]]);
      f[fa(x[i])]:=fa(y[i]);
     end;
  g:=true;
  for i:=1 to n do
    if d[i]<>2 then g:=false;
  if con and g then
    begin
      writeln('YES');writeln(0);
      //close(input);close(output);
      halt;
    end;
  fillchar(d,sizeof(d),0);
  for i:=1 to n do f[i]:=i;
  for i:=1 to m do
    if fa(x[i])=fa(y[i]) then
      begin
        writeln('NO');
        //close(input);close(output);
        halt;
      end else f[f[x[i]]]:=f[y[i]];
  for i:=1 to m do
    begin
      inc(d[x[i]]);inc(d[y[i]]);
    end;
  for i:=1 to n do
    if d[i]>2 then
      begin
        writeln('NO');
        //close(input);close(output);
        halt;
      end;
  writeln('YES');writeln(n-m);
  fillchar(a,sizeof(a),false);
  for k:=1 to n-m do
    begin
      for j:=1 to n-1 do if d[j]<2 then begin i:=j;break;break end;
      for j:=i+1 to n do
        if (d[j]<2) and ((k=n-m) or (fa(i)<>fa(j))) then
          begin
            px[k]:=i;py[k]:=j;inc(d[i]);inc(d[j]);f[fa(i)]:=f[j];break
          end;
    end;
  for i:=1 to n-m do
    if px[i]>py[i] then
      begin
        t:=px[i];px[i]:=py[i];py[i]:=t;
      end;
  for i:=1 to n-m-1 do
    for j:=i+1 to n-m do
      if (px[i]>px[j]) or ((px[i]=px[j]) and (py[i]>py[j])) then
        begin
          t:=px[i];px[i]:=px[j];px[j]:=t;
          t:=py[i];py[i]:=py[j];py[j]:=t;
        end;
  for k:=1 to n-m do writeln(px[k],' ',py[k]);
  //close(input);close(output);
end.