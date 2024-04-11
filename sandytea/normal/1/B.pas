program problem_b;

var
  test:longint;
  s,ans:ansistring;

function st(x:longint):ansistring;
  var
    temp:ansistring;
  begin
    str(x,temp);
    st:=temp;
  end;

function f1(s:ansistring):ansistring;
  var
    i,p,t,temp,row,column:longint;
  begin
    p:=1;
    while s[p] in ['A'..'Z'] do inc(p);
    val(copy(s,p,255),row,temp);
    dec(p);
    t:=1;column:=1;
    for i:=1 to p-1 do
      begin
        t:=t*26;
        inc(column,t);
      end;
    t:=1;
    for i:=p downto 1 do
      begin
        inc(column,(ord(s[i])-65)*t);
        t:=t*26;
      end;
    f1:='R'+st(row)+'C'+st(column);
  end;

function f2(s:ansistring):ansistring;
  var
    i,p,t,temp,len,row,column:longint;
    ss:ansistring;
  begin
    p:=pos('C',s);
    val(copy(s,2,p-2),row,temp);
    val(copy(s,p+1,255),column,temp);
    dec(column);
    len:=1;t:=26;
    while column>=t do
      begin
        dec(column,t);
        t:=t*26;
        inc(len);
      end;
    ss:=st(row);
    for i:=1 to len do
      begin
        ss:=chr(65+column mod 26)+ss;
        column:=column div 26;
      end;
    f2:=ss;
  end;

procedure init;
  begin
    readln(s);
  end;

procedure work;
  var
    p:longint;
    flag:boolean;
  begin
    p:=1;
    while s[p] in ['A'..'Z'] do inc(p);
    flag:=true;
    while(flag)and(p<=length(s))do
      begin
        if s[p] in ['A'..'Z'] then flag:=false;
        inc(p);
      end;
    if flag then ans:=f1(s)
            else ans:=f2(s);
  end;

procedure print;
  begin
    writeln(ans);
  end;

begin
  readln(test);
  while test>0 do
    begin
      dec(test);
      init;
      work;
      print;
    end;
end.