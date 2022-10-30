program Project1;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 04000000}
{$O+,R-,S-,Q-,I-}
{O-,R+,S+,Q+,I+}

uses
  Math,SysUtils;

var n,k,cur:int64;
    p,i:longint;
    s:string;

begin
    s:='';
    readln(n,k,p);
    for i := 1 to p do begin
        readln(cur);
        if n mod 2=0 then begin
            if cur mod 2=1 then begin
                cur:=n div 2-cur div 2;
                if cur<=k - n div 2 then s:=s+'X' else s:=s+'.';
            end
            else begin
                cur:=n div 2 - cur div 2+1;
                if cur<=k then s:=s+'X' else s:=s+'.';
            end;
        end
        else begin
            if k=0 then s:=s+'.' else
                if cur=n then s:=s+'X' else
                    if cur mod 2=1 then begin
                        cur:=n div 2-cur div 2;
                        if cur<=k-1 - n div 2 then s:=s+'X' else s:=s+'.';
                    end
                    else begin
                        cur:=n div 2 - cur div 2+1;
                        if cur<=k-1 then s:=s+'X' else s:=s+'.';
                    end;
        end;
    end;
    writeln(s);
    halt(0);
end.