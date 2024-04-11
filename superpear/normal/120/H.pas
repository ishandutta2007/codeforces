type ljb=^pear;
     pear=record
            num:longint;
            next:ljb;
          end;

var n,i,j,ls,sc,left,right,mid,o:longint;
    s,st:string;
    a:array[0..1000,0..1000] of string[5];
    tot:array[0..500000] of string[5];
    cc,mark,visit,last:array[0..500000] of longint;
    head,tail:array[0..1000] of ljb;
    b,cce:array[0..1000] of longint;
    p:ljb;

procedure swap(var a,b:string);
  var r:string;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j:longint;
      x:string;
  begin
    i:=l;
    j:=r;
    x:=tot[(l+r) div 2];
    repeat
      while tot[i]<x do inc(i);
      while x<tot[j] do dec(j);
      if i<=j then
        begin
          swap(tot[i],tot[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure push(x,y:longint);
  var p:ljb;
  begin
    new(p);
    p^.num:=y;
    p^.next:=nil;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

function dfs(s:longint):boolean;
  var p:ljb;
      c:longint;
  begin
    p:=head[s]^.next;
    while p<>nil do
      begin
        c:=p^.num;
        if visit[c]=0 then
          begin
            visit[c]:=1;
            if (last[c]=0) or dfs(last[c]) then
              begin
                last[c]:=s;
                exit(true);
              end;
          end;
        p:=p^.next;
      end;
    exit(false);
  end;

begin
  assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);
  readln(n);
  o:=0;
  fillchar(cce,sizeof(cce),0);
  for i:=1 to n do
    begin
      readln(s);
      ls:=length(s);
      fillchar(b,sizeof(b),0);
      while b[0]=0 do
        begin
          j:=ls;
          while b[j]=1 do
            begin
              b[j]:=0;
              dec(j);
            end;
          inc(b[j]);
          sc:=0;
          for j:=1 to ls do inc(sc,b[j]);
          if (sc<=4) and (sc>=1) then
            begin
              st:='';
              for j:=1 to ls do if b[j]=1 then st:=st+s[j];
              inc(cce[i]);
              a[i,cce[i]]:=st;
              inc(o);
              tot[o]:=st;
            end;
        end;
    end;
  sort(1,o);
  mark[1]:=1;
  cc[1]:=1;
  for i:=2 to o do
    begin
      if tot[i]=tot[i-1] then mark[i]:=mark[i-1] else mark[i]:=mark[i-1]+1;
      cc[mark[i]]:=i;
    end;
  for i:=1 to n do
    begin
      new(p);
      p^.num:=0;
      p^.next:=nil;
      head[i]:=p;
      tail[i]:=p;
    end;
  //for i:=1 to o do writeln(tot[i]);
  for i:=1 to n do
    begin
      for j:=1 to cce[i] do
        begin
          s:=a[i,j];
          left:=1;
          right:=o;
          repeat
            mid:=(left+right) div 2;
            if tot[mid]=s then break;
            if tot[mid]>s then right:=mid-1 else left:=mid+1;
          until false;
          push(i,mark[mid]+300);
          //writeln(i,' ',mark[mid]);
        end;
    end;
  fillchar(last,sizeof(last),0);
  for i:=1 to n do
    begin
      fillchar(visit,sizeof(visit),0);
      if not dfs(i) then
        begin
          writeln('-1');
          close(input);
          close(output);
          halt;
        end;
    end;
  for i:=1 to n do
    for j:=1 to o do
      if last[j+300]=i then writeln(tot[cc[j]]);
  close(input);
  close(output);
end.