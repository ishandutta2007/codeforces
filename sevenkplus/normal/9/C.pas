program C;
var s:string;
    i,k,n:longint;
begin
//  assign(input,'C.in');reset(input);
//  assign(output,'C.out');rewrite(output);
  readln(s);n:=length(s);k:=0;
  while not (s[length(s)] in ['0'..'9']) do delete(s,length(s),1);
  for i:=1 to n do
    if s[i]>'1' then
      begin
        inc(k,1 shl (n-i+1)-1);break;
      end else
    if s[i]='1' then inc(k,1 shl (n-i));
  writeln(k);
//  close(input);close(output);
end.