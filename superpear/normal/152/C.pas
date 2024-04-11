const bigp=1000000007;
var m,n,i,ans,e,j:longint;
    s:array[0..1000] of string;
    a:array['A'..'Z'] of longint;
begin
  readln(n,m);
  for i:=1 to n do
    readln(s[i]);
  ans:=1;
  for i:=1 to m do
    begin
      fillchar(a,sizeof(a),0);
      e:=0;
      for j:=1 to n do
        begin
          if a[s[j][i]]=0 then
            begin
              inc(e);
              a[s[j][i]]:=1;
            end;
        end;
      ans:=int64(ans)*e mod bigp;
    end;
  writeln(ans);
end.