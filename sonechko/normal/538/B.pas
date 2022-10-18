var n,m,i,j,k,ans,l,r:longint;
    b:array[1..10000]of LONGINT;
    s,t:string;
{procedure rec(s:string);
var i,l,tt:longint;
 begin
   val(s,tt);
   if (tt>n) then exit;
   inc(m);
   a[m]:=tt;
   if s[length(s)]='0' then begin s[length(s)]:='1'; rec(s); end else
   if pos('0',s)=0 then
    begin
      l:=length(s);
      s:='1';
      for i:=1 to l do
       s:=s+'0';
      rec(s);
    end else
    begin
      l:=0;
      for i:=length(s) downto 1 do
       if s[i]='0' then begin l:=i; break; end;
      s[l]:='1';
      for i:=l+1 to length(s) do
       s[i]:='0';
      rec(s);
    end;
 end;   }
  begin
    read(n);
    r:=0;
    while n>0 do
     begin
       str(n,s);
       t:='';
       for i:=1 to length(s) do
        if s[i]='0' then t:=t+'0' else t:=t+'1';
       val(t,k);
       n:=n-k;
       inc(r);
       b[r]:=k;
     end;
    writeln(r);
    for i:=1 to r do
     write(b[i],' ');
    writeln;
  end.