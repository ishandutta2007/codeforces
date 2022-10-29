program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var s1,s2,s3:string;
    num1:array[0..9]of longint;
    i:longint;

begin
    fillchar(num1,sizeof(num1),0);
    readln(s1);
    readln(s2);
    if s1='0' then begin
        if s2='0' then writeln('OK') else writeln('WRONG_ANSWER');
    end
    else begin
        s3:='';
        for i:= 1 to length(s1) do
            inc(num1[ord(s1[i])-ord('0')]);
        i:=1;
        while(num1[i]=0)do inc(i);
        s3:=s3+chr(i+ord('0'));
        dec(num1[i]);
        for i:=0 to 9 do
            while (num1[i]<>0)do begin
                s3:=s3+chr(i+ord('0'));
                dec(num1[i]);
            end;
        if s3=s2 then writeln('OK') else writeln('WRONG_ANSWER');
    end;
    halt(0);
end.