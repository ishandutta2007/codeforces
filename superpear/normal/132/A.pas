var s:string;
    ls,i,j,t,c,e,last:longint;
    a:array[0..10] of longint;

begin
  readln(s);
  ls:=length(s);
  last:=0;
  for i:=1 to ls do
    begin
      c:=ord(s[i]);
      t:=8;
      fillchar(a,sizeof(a),0);
      while c>0 do
        begin
          a[t]:=c mod 2;
          c:=c div 2;
          dec(t);
        end;
      e:=0;
      for j:=1 to 8 do e:=e*2+a[9-j];
      writeln((last-e+25600000) mod 256);
      last:=e;
    end;
end.