program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var num,n,m,i,j,cur:longint;
    a:array[1..100]of longint;
    s:array[1..100]of string;
    res:array[1..100]of longint;
    aa,b:longint;
    sp:string;

begin
    readln(n,m);
    for i:= 1 to n do
        read(a[i]);
    readln;
    for i:= 2 to n do
        for j:= n downto i do
            if a[j]<a[j-1] then begin
                aa:=a[j];
                a[j]:=a[j-1];
                a[j-1]:=aa;
            end;
    for i:= 1 to m do
        readln(s[i]);
    for i:= 2 to m do
        for j:=m downto i do
            if s[j]<s[j-1] then begin
                sp:=s[j];
                s[j]:=s[j-1];
                s[j-1]:=sp;
            end;
    num:=1;
    cur:=1;
    for i:=2 to m do begin
        if s[i]<>s[i-1] then begin
            res[num]:=cur;
            inc(num);
            cur:=1;
        end
        else inc(cur);
    end;
    res[num]:=cur;
    for i:= 2 to num do
        for j:= num downto i do
            if res[j]<res[j-1] then begin
                aa:=res[j];
                res[j]:=res[j-1];
                res[j-1]:=aa;
            end;
    aa:=0;
    for i:= 1 to num do
        aa:=aa+res[num-i+1]*a[i];
    b:=0;
    for i:=1 to num do
        b:=b+res[num-i+1]*a[n-i+1];
    writeln(aa,' ',b);
    halt(0);
end.