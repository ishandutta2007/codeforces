const maxn=1000000;
      big=500000;

var a,f:array[0..maxn] of longint;
    s:ansistring;
    n,i,c,e,max,maxk:longint;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a) else exit(b);
  end;

function low(s:longint):longint;
  begin
    exit(s and (-s));
  end;

procedure put(x,s:longint);
  begin
    while x<=maxn do
      begin
        f[x]:=min(f[x],s);
        x:=x+low(x);
      end;
  end;

function getmin(s:longint):longint;
  var ans:longint;
  begin
    ans:=maxlongint;
    while s>0 do
      begin
        ans:=min(ans,f[s]);
        s:=s-low(s);
      end;
    exit(ans);
  end;

begin
  readln(s);
  n:=length(s);
  for i:=1 to n do
    begin
      if s[i] in ['A','E','I','O','U','a','e','i','o','u'] then
        a[i]:=-1
      else
        a[i]:=2;
    end;
  filldword(f,sizeof(f) div 4,maxlongint);
  e:=big;
  max:=0;
  maxk:=0;
  put(e,0);
  for i:=1 to n do
    begin
      e:=e+a[i];
      c:=getmin(e);
      if i-c>max then
        begin
          max:=i-c;
          maxk:=1;
        end
      else
        if i-c=max then inc(maxk);
      put(e,i);
    end;
  if max=0 then writeln('No solution') else writeln(max,' ',maxk);
end.