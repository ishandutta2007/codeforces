program E;
var a:array[1..50,1..50,0..1,0..1,0..1] of int64;
    k,l60,t:int64;
    n,i:longint;
    s:string[100];
function g(l,r,v,f,b:longint):int64;
  var t:int64;
      cl,cr,vv,ff,bb:longint;
  begin
    if l>r then
      if (f=0) and (b<>0) then exit(0) else exit(1);
    t:=a[l,r,v,f,b];
    if t<>0 then exit(t);
    for cl:=0 to 1 do
      begin
        if (l<=i) and (s[l]<>chr(ord('0')+cl)) then continue;
        for cr:=0 to 1 do
          begin
            if (r<=i) and (s[r]<>chr(ord('0')+cr)) then continue;
            if (l=r) and (cl<>cr) then continue;
            if (v=0) and (cl>cr) then continue;
            if (f=0) and (1-cr<cl) then continue;
            if cl<cr then vv:=1 else vv:=v;
            if cl<1-cr then ff:=1 else ff:=f;
            if cr<1-cl then bb:=0 else
              if cr>1-cl then bb:=1 else bb:=b;
            inc(t,g(l+1,r-1,vv,ff,bb));
            if t>l60 then t:=l60;
          end;
      end;
    a[l,r,v,f,b]:=t;exit(t);
  end;
begin
//  assign(input,'E.in');reset(input);
//  assign(output,'E.out');rewrite(output);
  readln(n,k);inc(k);
  l60:=1;for i:=1 to 60 do l60:=l60*2;
  s:='';
  for i:=1 to n do
    begin
      s:=s+'0';
      fillchar(a,sizeof(a),0);
      t:=g(1,n,0,0,0);
      if t>=k then continue;
      dec(k,t);
      if i=1 then
        begin
          writeln(-1);
          break;
        end else s[i]:='1';
    end;
  if s<>'0' then writeln(s);
//  close(input);close(output);
end.