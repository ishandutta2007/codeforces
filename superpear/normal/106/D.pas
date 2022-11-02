var st:string;
    a,sum:array[0..1000,0..1000] of longint;
    x,y:array['A'..'Z'] of longint;
    ic,chr:char;
    ch:array[0..100000] of char;
    len:array[0..100000] of longint;
    m,n,i,j,k,xc,yc,x1,y1,flag:longint;

function getsum(x1,y1,x2,y2:longint):longint;
  begin
    if x1<1 then exit(1);
    if y1<1 then exit(1);
    if x2>m then exit(1);
    if y2>n then exit(1);
    exit(sum[x2,y2]-sum[x1-1,y2]-sum[x2,y1-1]+sum[x1-1,y1-1]);
  end;

begin
  readln(m,n);
  for i:=1 to m do
    begin
      for j:=1 to n do
        begin
          read(chr);
          if chr='#' then a[i,j]:=1 else a[i,j]:=0;
          if (chr>='A') and (chr<='Z') then
            begin
              x[chr]:=i;
              y[chr]:=j;
            end;
        end;
      readln;
    end;
  for i:=1 to m do
    for j:=1 to n do
      sum[i,j]:=sum[i-1,j]+sum[i,j-1]-sum[i-1,j-1]+a[i,j];
  readln(k);
  for i:=1 to k do
    readln(ch[i],len[i]);
  st:='';
  for ic:='A' to 'Z' do
    begin
      x1:=x[ic];
      y1:=y[ic];
      flag:=1;
      for j:=1 to k do
        begin
          if ch[j]='N' then
            begin
              xc:=x1-len[j];
              yc:=y1;
              if getsum(xc,yc,x1,y1)>0 then
                begin
                  flag:=0;
                  break;
                end;
              x1:=xc;y1:=yc;
            end;
          if ch[j]='S' then
            begin
              xc:=x1+len[j];
              yc:=y1;
              if getsum(x1,y1,xc,yc)>0 then
                begin
                  flag:=0;
                  break;
                end;
              x1:=xc;y1:=yc;
            end;
          if ch[j]='W' then
            begin
              xc:=x1;
              yc:=y1-len[j];
              if getsum(xc,yc,x1,y1)>0 then
                begin
                  flag:=0;
                  break;
                end;
              x1:=xc;y1:=yc;
            end;
          if ch[j]='E' then
            begin
              xc:=x1;
              yc:=y1+len[j];
              if getsum(x1,y1,xc,yc)>0 then
                begin
                  flag:=0;
                  break;
                end;
              x1:=xc;y1:=yc;
            end;
        end;
      if flag=1 then st:=st+ic;
    end;
  if st='' then st:='no solution';
  writeln(st);
end.