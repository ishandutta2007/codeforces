program B_;
var p,q:array[0..5] of longint;
    n,i,j,a,b:longint;
    s:string;
function f(s:string):boolean;
  begin
    exit((s[1]='R') and (s[2] in ['0'..'9']) and (pos('C',s)<>0));
  end;
function t1(a:longint):string;
  var s:string;
  begin
    s:='';
    while a<>0 do
      if a mod 26=0 then
      begin
        s:='Z'+s;
        a:=a div 26-1;
      end else
      begin
        s:=chr(ord('A')+a mod 26-1)+s;
        a:=a div 26;
      end;
    t1:=s;
  end;
function t2(s:string):longint;
  var i,x,l:longint;
  begin
    x:=0;l:=length(s);
    for i:=l-1 downto 0 do inc(x,p[i]*(ord(s[l-i])-ord('A')+1));
    t2:=x;
  end;
begin
 // assign(input,'B.in');reset(input);
 // assign(output,'B.out');rewrite(output);
  p[0]:=1;for i:=1 to 5 do p[i]:=p[i-1]*26;
  q[0]:=0;for i:=1 to 5 do q[i]:=q[i-1]+p[i];
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      if f(s) then
        begin
          j:=2;a:=0;
          while s[j]<>'C' do
            begin
              a:=a*10+ord(s[j])-ord('0');inc(j);
            end;
          b:=0;
          for j:=j+1 to length(s) do b:=b*10+ord(s[j])-ord('0');
          writeln(t1(b),a);
        end else
        begin
          j:=1;while not (s[j] in['0'..'9']) do inc(j);
          writeln('R',copy(s,j,10),'C',t2(copy(s,1,j-1)));
        end;
    end;
  //close(input);close(output);
end.