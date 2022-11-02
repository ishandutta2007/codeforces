var l,r:int64;
    f:array[0..20,0..20,0..20,0..1] of int64;

function getans(num:int64):int64;
  var ans:int64;
      s:string;
      n,i,j,k,up,e:longint;
  begin
    str(num,s);
    n:=length(s);
    fillchar(f,sizeof(f),0);
    f[0,0,0,1]:=1;
    ans:=0;
    for i:=0 to n-1 do
      for j:=0 to 9 do
        for e:=0 to 9 do
        begin
          up:=ord(s[i+1])-48;
          for k:=0 to 9 do
            begin
              if j<>0 then
                f[i+1,j,k,0]:=f[i+1,j,k,0]+f[i,j,e,0]
              else
                f[i+1,k,k,0]:=f[i+1,k,k,0]+f[i,j,e,0];
            end;
          for k:=0 to up-1 do
            begin
              if j<>0 then
                f[i+1,j,k,0]:=f[i+1,j,k,0]+f[i,j,e,1]
              else
                f[i+1,k,k,0]:=f[i+1,k,k,0]+f[i,j,e,1];
            end;
          if j<>0 then
            f[i+1,j,up,1]:=f[i+1,j,up,1]+f[i,j,e,1]
          else
            f[i+1,up,up,1]:=f[i+1,up,up,1]+f[i,j,e,1];
        end;
    for i:=1 to 9 do
      ans:=ans+f[n,i,i,0]+f[n,i,i,1];
    exit(ans);
  end;

begin
  readln(l,r);
  writeln(getans(r)-getans(l-1));
end.