const bigp=1000000007;

var s:ansistring;
    f:array[0..700,0..700,0..2,0..2] of longint;
    n,i,j,ans:longint;
    a:array[0..700] of longint;

function search(l,r,lc,rc:longint):longint;
  var e,s,i,j,f1,f2:longint;
  begin
    if f[l,r,lc,rc]=-1 then
      begin
        f[l,r,lc,rc]:=0;
        e:=l;
        s:=0;
        repeat
          s:=s+a[e];
          inc(e);
        until s=0;
        dec(e);
        if e<>r then
          begin
            for i:=0 to 2 do
              for j:=0 to 2 do
                if (i=0) or (j=0) or (i<>j) then
                  f[l,r,lc,rc]:=(f[l,r,lc,rc]+int64(search(l,e,lc,i))*search(e+1,r,j,rc)) mod bigp;
          end
        else
          begin
            if lc=0 then f1:=1 else f1:=0;
            if rc=0 then f2:=1 else f2:=0;
            if f1+f2=1 then
              begin
                if l+1=r then f[l,r,lc,rc]:=1 else
                  begin
                    for i:=0 to 2 do
                      for j:=0 to 2 do
                        if ((i=0) or (i<>lc)) and ((j=0) or (j<>rc)) then
                          f[l,r,lc,rc]:=(f[l,r,lc,rc]+int64(search(l+1,r-1,i,j))) mod bigp;
                  end;
              end;
          end;
      end;
    exit(f[l,r,lc,rc]);
  end;

begin
  readln(s);
  n:=length(s);
  for i:=1 to n do
    if s[i]='(' then a[i]:=1 else a[i]:=-1;
  fillchar(f,sizeof(f),255);
  ans:=0;
  for i:=0 to 2 do
    for j:=0 to 2 do
      ans:=(ans+search(1,n,i,j)) mod bigp;
  writeln(ans);
end.