const
  inputfile= 'rank.in';
  outputfile='rank.out';
  maxn=100005;
var
  n:integer;
  node,next:array[1..maxn shl 1]of integer;
  f,first,wei:array[1..maxn]of integer;

procedure init;
var
  i,p,a,b:integer;
begin
  //assign(input,inputfile);reset(input);
  readln(n);
  fillchar(first,sizeof(first),0);
  p:=0;
  for i:=1 to n-1 do begin
    readln(a,b);
    inc(p);node[p]:=b;next[p]:=first[a];first[a]:=p;
    inc(p);node[p]:=a;next[p]:=first[b];first[b]:=p;
  end;
  //close(input)
end;

procedure dfs(par,k:integer);
var
  i,s,g,t:integer;
begin
  i:=first[k];
  g:=0;s:=0;
  wei[k]:=1;
  while i<>0 do begin
    if node[i]<>par then begin
      t:=node[i];
      dfs(k,t);
      g:=g or (f[t] and s);
      s:=s or f[t]
    end;
    i:=next[i]
  end;
  //while ((s and (1 shl (wei[k]-1)))<>0)do inc(wei[k]);
  //writeln(s);
  if g>0 then begin
    while g and (g-1)<>0 do g:=g and (g-1);
    s:=s or g or (g-1)
  end;
  f[k]:=s+1;
  //while (1 shl (wei[k]-1)<=g)do inc(wei[k]);
  while (f[k] and (1 shl (wei[k]-1))=0)do inc(wei[k]);
  //writeln(k,' ',f[k],' ',g,' ',wei[k]);
end;

procedure work;
var
  ans,i:integer;
begin
  fillchar(f,sizeof(f),0);
  dfs(0,1);
  ans:=1;
  while 1 shl ans<=f[1] do inc(ans);
  //assign(output,outputfile);rewrite(output);
  if (ans > 26) then writeln('Impossible!')
  else
  for i:=1 to n do write(char(91-wei[i]),' ');writeln;
  //close(output)
end;

begin
  init;
  work;
  //while (true) do;
end.