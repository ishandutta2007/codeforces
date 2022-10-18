const a:array[1..10]of string=('7','77','777','7777','77777','777777','7777777','77777777','777777777','7777777777');
      b:array[1..10]of string=('4','44','444','4444','44444','444444','4444444','44444444','444444444','4444444444');
var n,m,i,j,k,ans,l,r:longint;
    s,t:string;
  begin
    readln(s);
    t:='4';
    ans:=1;
    while s<>t do
     begin
       if t=a[length(t)] then begin inc(ans); t:=b[length(t)+1]; continue; end;
       i:=length(t);
       while t[i]='7' do
        dec(i);
       t[i]:='7';
       for j:=i+1 to length(t) do
        t[j]:='4';
        inc(ans);
     end;
    writeln(ans);
  end.