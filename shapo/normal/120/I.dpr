program task;

{$APPTYPE CONSOLE}
//{$O-,R+,S+,Q+,I+}
{$O+,R-,S-,Q-,I-}

uses
  Math,
  SysUtils;

const maxl=9;
    cur:array[0..maxl]of longint = (6,2,5,5,4,5,6,3,7,6);
    pp:array[0..maxl,0..maxl]of longint =
   ((6,2,4,4,3,4,5,3,6,5),
    (2,2,1,2,2,1,1,2,2,2),
    (4,1,5,4,2,3,4,2,5,4),
    (4,2,4,5,3,4,4,3,5,5),
    (3,2,2,3,4,3,3,2,4,4),
    (4,1,3,4,3,5,5,2,5,5),
    (5,1,4,4,3,5,6,2,6,5),
    (3,2,2,3,2,2,2,3,3,3),
    (6,2,5,5,4,5,6,3,7,6),
    (5,2,4,5,4,5,5,3,6,6));
    maxn=200000;

var s,res:string;
    a:array[0..maxn]of longint;
    b:array[1..maxn,0..maxl]of longint;
    i,n,j:longint;

function num(c:char):longint;
begin
    num:=ord(c)-ord('0');
end;

procedure init;
var i,j:longint;
begin
    a[0]:=cur[8]*n;
    for i:=1 to n do
        a[i]:=a[i-1]-cur[8]+cur[num(s[i])];
    for i:=n+1 to 2*n do
        a[i]:=a[i-1]-cur[num(s[i-n])]+pp[num(s[i-n]),num(s[i])];
    for i:=1 to n do
        for j:=0 to maxl do
            b[i][j]:=a[i-1]-cur[8]+cur[j];
    for i:=n+1 to 2*n do
        for j:=0 to maxl do
            b[i][j]:=a[i-1]-cur[num(s[i-n])]+pp[num(s[i-n]),j];
end;

procedure make(x,y:longint);
var i,j,cc,cp:longint;
begin
    cc:=b[x][y];
    for i:=x+1 to 2*n do begin
        cp:=0;
        j:=-1;
        while (j<9) and (cp<=a[2*n]) do begin
            inc(j);
            cp:=cc-cur[num(s[i-n])]+pp[num(s[i-n]),j];
        end;
        cc:=cp;
        res:=res+chr(ord('0')+j);
    end;
end;

procedure make1(x,y:longint);
var cc,cp,i,j:longint;
begin
    cc:=b[x][y];
    for i:=x+1 to n do begin
        cp:=0;
        j:=-1;
        while(j<9)and (cp<=a[2*n]) do begin
            inc(j);
            cp:=cc-cur[8]+cur[j];
        end;
        cc:=cp;
        res:=res+chr(ord('0')+j);
    end;
    for i:=n+1 to 2*n do begin
        cp:=0;
        j:=-1;
        while (j<9) and (cp<=a[2*n]) do begin
            inc(j);
            cp:=cc-cur[num(res[i-n])]+pp[num(res[i-n]),j];
        end;
        cc:=cp;
        res:=res+chr(ord('0')+j);
    end;
end;

begin
    assign(input,'input.txt');
    assign(output,'output.txt');
    readln(s);
    n:=length(s) div 2;
    init;
    res:='';
    for i:= 2*n downto n+1 do begin
        j:=ord(s[i])-ord('0')+1;
        while (j<=9) do begin
            if b[i][j]>a[2*n]then begin
                res:=copy(s,1,i-1)+chr(ord('0')+j);
                make(i,j);
                writeln(res);
                halt(0);
            end;
            inc(j);
        end;
    end;
    for i:= n downto 1 do begin
        j:=ord(s[i])-ord('0')+1;
        while(j<=9) do begin
            if b[i][j]>a[2*n] then begin
                res:=copy(s,1,i-1)+chr(ord('0')+j);
                make1(i,j);
                writeln(res);
                halt(0);
            end;
            inc(j);
        end;
    end;
    writeln(-1);
    halt(0);
end.