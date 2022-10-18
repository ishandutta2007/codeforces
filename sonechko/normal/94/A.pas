var n,m,i,j,k,ans,l,r:longint;
    s,t:string;
    a:array[1..8]of longint;
  begin
    readln(s);
    for i:=0 to 9 do
     begin
       readln(t);
       if copy(s,1,10)=t then a[1]:=i;
       if copy(s,11,10)=t then a[2]:=i;
       if copy(s,21,10)=t then a[3]:=i;
       if copy(s,31,10)=t then a[4]:=i;
       if copy(s,41,10)=t then a[5]:=i;
       if copy(s,51,10)=t then a[6]:=i;
       if copy(s,61,10)=t then a[7]:=i;
       if copy(s,71,10)=t then a[8]:=i;
     end;
    for i:=1 to 8 do
     write(a[i]);
    writeln;
  end.