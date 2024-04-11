program game;

//{$APPTYPE CONSOLE}
//{$R+,S+,Q+,O-,I+}
{$OPTIMIZATION LEVEL2}
{$R-,S-,Q-,I-}

uses
  Math,
  SysUtils;

var n, i, k, z : longint;
    sm, res : array[0..200000] of longint;
    xorr : array[0..200000]of longint;
    mex : array[0..200000] of longint;

function ok(x, y : longint) : boolean;
begin
	ok := ((x - ((y - 1) * y) div 2) mod y = 0)
    and ((x - ((y - 1) * y) div 2) div y > 0);
end;

begin
	fillchar(mex, sizeof(mex), 0);
    readln(n);
	sm[0] := 1;
    sm[1] := 0;
    sm[2] := 0;
    xorr[0] := 1;
    xorr[1] := 0;
    xorr[2] := 0;
    for i := 1 to n do begin
    	res[i] := 0;
        sm[i] := 0;
    	k := 2;
        while ((k * (k - 1)) div 2 <= i)  do begin
        	if ok(i, k) then begin
            	z := (i - ((k - 1) * k) div 2) div k;
                mex[xorr[z + k - 1] xor xorr[z - 1]] := i;
                if xorr[z + k - 1] xor xorr[z - 1] = 0 then
                	if res[i] = 0 then res[i] := k;
            end;
            k := k + 1;
        end;
        k := 0;
        while (mex[k] = i) do inc(k);
        sm[i] := k;
        xorr[i] := xorr[i - 1] xor sm[i];
    end;
    {for i := 1 to n do
    	write(res[i], ' ');
    writeln;}
	if res[n] = 0 then writeln('-1') else writeln(res[n]);
    readln;
    halt(0);
end.