var m,n,i,j,a1,b1,c1,c4,c5,c6,ans:longint;
    a,s:array[0..1000,0..1000] of longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

function sum(a,b,c,d:longint):longint;
  begin
    exit(s[c,d]-s[a-1,d]-s[c,b-1]+s[a-1,b-1]);
  end;

begin
 assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);
  readln(n,m);
  fillchar(s,sizeof(s),0);
  for i:=1 to n do
    for j:=1 to m do
      begin
        read(a[i,j]);
        s[i,j]:=s[i-1,j]+s[i,j-1]-s[i-1,j-1]+a[i,j];
      end;
  readln(a1,b1,c1);
  if a1>b1 then swap(a1,b1);
  if a1>c1 then swap(a1,c1);
  if b1>c1 then swap(b1,c1);
  ans:=0;
  for i:=1 to n-2 do
    for j:=i+1 to n-1 do
      begin
        c4:=sum(1,1,i,m);
        c5:=sum(i+1,1,j,m);
        c6:=sum(j+1,1,n,m);
        if c4>c5 then swap(c4,c5);
        if c4>c6 then swap(c4,c6);
        if c5>c6 then swap(c5,c6);
        if (c4=a1) and (c5=b1) and (c6=c1) then inc(ans);
      end;
  for i:=1 to m-2 do
    for j:=i+1 to m-1 do
      begin
        c4:=sum(1,1,n,i);
        c5:=sum(1,i+1,n,j);
        c6:=sum(1,j+1,n,m);
        if c4>c5 then swap(c4,c5);
        if c4>c6 then swap(c4,c6);
        if c5>c6 then swap(c5,c6);
        if (c4=a1) and (c5=b1) and (c6=c1) then inc(ans);
      end;
  writeln(ans);
 close(input);
  close(output);
end.