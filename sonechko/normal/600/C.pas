var n,m,i,j,k,ans,l,r:longint;
    a:array['a'..'z']of longint;
    s:ansistring;
    ch,h,ll:char;
procedure sort(l,r: longint);
      var
         i,j: longint;
         x,y:char;
      begin
         i:=l;
         j:=r;
         x:=s[(l+r) div 2];
         repeat
           while s[i]<x do
            inc(i);
           while x<s[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=s[i];
                s[i]:=s[j];
                s[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
  begin
    readln(s);
    for i:=1 to length(s) do
     inc(a[s[i]]);
    s:='';
    for ch:='a' to 'z' do
     while (a[ch]>1) do
      begin
        s:=s+ch;
        dec(a[ch],2);
      end;
    ll:=' ';
    for ch:='a' to 'z' do
     if a[ch]=1 then
      begin
        for h:='z' downto 'a' do
         if (h<>ch) and (a[h]=1) then begin s:=s+ch; a[ch]:=0; a[h]:=0; break; end;
        if a[ch]=1 then begin ll:=ch; break; end;
      end;
    if length(s)<>0 then sort(1,length(s));
    write(s);
    if ll<>' ' then write(ll);
    for i:=length(s) downto 1 do
     write(s[i]);
    writeln;
  end.