var n,m,i,j,k,ans,l,r:longint;
    s:string;
    a:array[0..9]of longint;
  begin
    a[0]:=2;
    a[1]:=7;
    a[2]:=2;
    a[3]:=3;
    a[4]:=3;
    a[5]:=4;
    a[6]:=2;
    a[7]:=5;
    a[8]:=1;
    a[9]:=2;
    readln(s);
    val(s[1],l);
    val(s[2],r);
    writeln(a[l]*a[r]);
  end.