
program cf200_4;

type lot=record
  l,r:longint;
  ch:char;
end;

var
    s:ansistring;
    i,le,j,k,m,n,ii:longint;
    a:array[-1..100020] of lot;
    f:boolean;

begin
  readln(s);
  le:=length(s);
  if le mod 2<>0 then begin
    writeln('No');
    halt;
  end;
  fillchar(a,sizeof(a),0);
  a[-1].r:=1;
  for i:= 1 to le do
    with a[i] do
      begin
        l:=i-1;
        r:=i+1;
        ch:=s[i];
      end;
  repeat
    k:=le;
    i:=-1;
    repeat
      if (a[a[a[i].r].r].r<>0) and (a[a[i].r].ch=a[a[a[i].r].r].ch) then begin
        a[i].r:=a[a[a[i].r].r].r;
        a[a[i].r].l:=i;
        dec(le,2);
        i:=a[i].l;
      end
      else i:=a[i].r;
    until i=0;
  until (k=le) or (le=0);
  if le=0 then writeln('Yes') else writeln('No');
end.