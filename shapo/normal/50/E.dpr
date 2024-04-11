program task;

{$APPTYPE CONSOLE}{$O+,R-,S-,Q-,I-}

uses
  Math,
  SysUtils;

var n,m,i,k,l1,l2:int64;
    res:int64;

begin
    readln(n,m);
    res:=0;
    i:=1;
    while (i<=n) do begin
        k:=(i*i-1);
        if k>m then res:=res+2*m else res:=res+2*k;
        if k<m then res:=res+1;
        i:=i+1;
    end;
    i:=2*n;
    while i>0 do begin
        l1:=i div 2 + 1;
        l2:=min((i*i+m) div (2*i),n);
        l2:=min(l2,n);
        k:=max(0,l2-l1+1);
        res:=res - max(0,k-1);
        i:=i-1;
    end;
    writeln(res);
    halt(0);
end.