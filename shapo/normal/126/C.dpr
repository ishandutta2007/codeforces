program task;

{$APPTYPE CONSOLE}
//{$O-,R+,S+,Q+,I+}
{$O+,R-,S-,Q-,I-}

uses
  Math,
  SysUtils;

const maxn=2001;

var n:longint;
    res:longint;
    sm:array[0..maxn,0..maxn]of shortint;
    l,up:array[0..maxn,0..maxn]of longint;

procedure input_data;
var i,j:longint;
    c:char;
begin
    //assign(input,'input.txt');
    readln(n);
    for i:= 1 to n do begin
        for j:= 1 to n do begin
            read(c);
            sm[i,j]:=ord(c)-ord('0');
        end;
        readln;
    end;
end;

procedure obr;
var i,j,k,cur:longint;
begin
    fillchar(l,sizeof(l),0);
    fillchar(up,sizeof(up),0);
    for k:=n-1 downto 1 do begin
        i:=1;
        while (k+i<=n) do begin
            j:=k+i;
            cur:=up[i-1,j]+l[i,j+1];
            if (cur mod 2 <> sm[i,j]) then begin
                up[i,j]:=up[i-1,j]+1;
                l[i,j]:=l[i,j+1]+1;
            end
            else begin
                up[i,j]:=up[i-1,j];
                l[i,j]:=l[i,j+1];
            end;
            inc(i);
        end;
    end;
    for k:=n-1 downto 1 do begin
        j:=1;
        while(k+j<=n)do begin
            i:=k+j;
            cur:=up[i+1,j]+l[i,j-1];
            if (cur mod 2 <> sm[i,j]) then begin
                up[i,j]:=up[i+1,j]+1;
                l[i,j]:=l[i,j-1]+1;
            end
            else begin
                up[i,j]:=up[i+1,j];
                l[i,j]:=l[i,j-1];
            end;
            inc(j);
        end;
    end;
    for i:= 1 to n do begin
        cur:=up[i-1,i]+up[i+1,i]+l[i,i-1]+l[i,i+1];
        if cur mod 2<> sm[i,i] then begin
            up[i,i]:=up[i-1,i]+up[i+1,i]+1;
            l[i,i]:=l[i,i-1]+l[i,i+1]+1;
        end
        else begin
            up[i,i]:=up[i-1,i]+up[i+1,i];
            l[i,i]:=l[i,i-1]+l[i,i+1];
        end;
        res:=res+up[i,i]+l[i,i];
    end;
    res:=res div 2;
end;

begin
    res:=0;
    input_data;
    obr;
    writeln(res);
    halt(0);
end.