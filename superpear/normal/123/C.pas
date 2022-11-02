var m,n,i,j,xc,mink,minc,k:longint;
    kc:int64;
    a,min:array[0..10000] of longint;
    f:array[0..500,0..500] of int64;

begin
//  assign(input,'C.inp');
//  reset(input);

  readln(m,n,kc);
  filldword(min,sizeof(min) div 4,maxlongint);
  for i:=1 to m do
    for j:=1 to n do
      begin
        read(xc);
        if xc<min[i+j-1] then min[i+j-1]:=xc;
      end;
  fillchar(a,sizeof(a),0);
  for i:=1 to m+n-1 do
    begin
      mink:=maxlongint;
      minc:=maxlongint;
      for j:=1 to m+n-1 do
        if (a[j]=0) and (min[j]<minc) then
          begin
            minc:=min[j];
            mink:=j;
          end;
      a[mink]:=1;
      fillchar(f,sizeof(f),0);
      f[0,0]:=1;
      for j:=0 to m+n-2 do
        for k:=0 to m+n-2 do
          begin
            if f[j,k]>kc+1 then f[j,k]:=kc+1;
            if a[j+1]=1 then
              f[j+1,k+1]:=int64(f[j+1,k+1])+f[j,k];
            if a[j+1]=2 then
              if k>0 then
                f[j+1,k-1]:=int64(f[j+1,k-1])+f[j,k];
            if a[j+1]=0 then
              begin
                f[j+1,k+1]:=int64(f[j+1,k+1])+f[j,k];
                if k>0 then f[j+1,k-1]:=int64(f[j+1,k-1])+f[j,k];
              end;
          end;
      //writeln(f[m+n-1,0],' ',mink);
      if kc>f[m+n-1,0] then
        begin
          a[mink]:=2;
          kc:=kc-f[m+n-1,0];
        end;
    end;
  for i:=1 to m do
    begin
      for j:=1 to n do
        if a[i+j-1]=1 then write('(') else write(')');
      writeln;
    end;

//  close(input);
//  close(output);
end.