program Project1;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 04000000}
{O+,R-,S-,Q-,I-}
{$O-,R+,S+,Q+,I+}

uses
  Math,SysUtils;

var n:longint;

begin
    readln(n);
    if (n<=10)or(n>21) then writeln(0)else
        if (n=20) then writeln(15) else writeln(4);
    halt(0);
end.