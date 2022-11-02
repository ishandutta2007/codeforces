const kuai=300;

var ans,sum:array[0..210000] of int64;
    a,x,y,z,count,last,back,cc:array[0..210000] of longint;
    hash,js:array[0..1000000] of longint;
    nans:int64;
    m,n,i,j,c,l,r,now:longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j,c:longint;
  begin
    i:=l;
    j:=r;
    c:=y[l+random(r-l+1)];
    repeat
      while y[i]<c do inc(i);
      while c<y[j] do dec(j);
      if i<=j then
        begin
          swap(x[i],x[j]);
          swap(y[i],y[j]);
          swap(z[i],z[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

function place(s:longint):longint;
  begin
    if s=0 then exit(0);
    exit((s-1) div kuai+1);
  end;

function value(s:longint):int64;
  begin
    exit(int64(a[s])*((js[a[s]]-cc[s])*2+1));
  end;

begin
  randomize;

  readln(n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do
    begin
      readln(x[i],y[i]);
      z[i]:=i;
    end;
  sort(1,m);

  fillchar(hash,sizeof(hash),0);
  fillchar(count,sizeof(count),0);
  fillchar(back,sizeof(back),0);
  fillchar(last,sizeof(last),0);
  fillchar(cc,sizeof(cc),0);
  for i:=1 to n do
    begin
      last[i]:=hash[a[i]];
      hash[a[i]]:=i;
      cc[i]:=cc[last[i]]+1;
      if place(i)=place(last[i]) then
        begin
          back[i]:=back[last[i]];
          count[i]:=count[last[i]]+1;
        end
      else
        begin
          back[i]:=last[i];
          count[i]:=1;
        end;
    end;

  fillchar(ans,sizeof(ans),0);
  fillchar(sum,sizeof(sum),0);
  fillchar(js,sizeof(js),0);
  now:=1;
  for i:=1 to n do
    begin
      inc(sum[place(i)],a[i]);
      c:=last[i];
      while place(c)=place(i) do
        begin
          inc(sum[place(c)],2*a[c]);
          c:=last[c];
        end;
      while c>0 do
        begin
          inc(sum[place(c)],2*a[c]*int64(count[c]));
          c:=back[c];
        end;
      inc(js[a[i]]);
      while (now<=m) and (y[now]=i) do
        begin

          l:=x[now];
          r:=y[now];
          nans:=0;
          repeat
            nans:=nans+value(r);
            r:=r-1;
          until (r<l) or (place(r)<>place(y[now]));

          if r>=l then
            begin
              while place(r)>place(l) do
                begin
                  nans:=nans+sum[place(r)];
                  r:=r-kuai;
                end;
              for j:=r downto l do
                nans:=nans+value(j);
            end;
          ans[z[now]]:=nans;

          inc(now);
        end;
    end;

  for i:=1 to m do
    writeln(ans[i]);
end.