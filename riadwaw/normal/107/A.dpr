program n1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var m,n,i,a,b,c,k:integer;
    nxt,v,min,tnk,krn:array[1..1000] of integer;
    vh:array[1..1000] of boolean;

begin
  readln(n,m);
  for i:=1 to n do begin
    vh[i]:=false;
    nxt[i]:=i;
  end;
  for i:=1 to m do begin
    readln(a,b,c);
    vh[b]:=true;
    nxt[a]:=b;
    v[a]:=c;
  end;
  k:=0;
  for i:=1 to n do begin
    if (not vh[i])and(nxt[i]<>i) then begin
      a:=i;
      inc(k);
      min[k]:=v[i];
      tnk[k]:=i;
      repeat
        if v[a]<min[k] then min[k]:=v[a];
        a:=nxt[a];
      until nxt[a]=a;
      krn[k]:=a;
    end;
  end;
  writeln(k);
  for i:=1 to k do begin
    writeln(tnk[i],' ',krn[i],' ',min[i]);
  end;
end.