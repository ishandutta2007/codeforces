{$MODE DELPHI}
{$D+,I+,L+,Q+,R+,S+,O-,H+}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
{$M 1000000000}
Uses Math,SysUtils;
type int=longint;
const inf=maxlongint div 2;
var n,m,i,j,k,ans,x,y,w,msk:int;
        a:array[0..100,0..100]of int;
        d:array[0..1 shl 20]of int;
        st:array[0..100]of int;
begin
        {assign(input,'d.in');
        reset(input);
        assign(output,'d.out');
        rewrite(output);}
        readln(n,m);
        for i:=1 to n do
                for j:=1 to n do begin
                        if i<>j then 
                                a[i][j]:=inf
                        else
                                a[i][j]:=0;
                end;
        ans:=0;
        for i:=1 to m do begin
                read(x,y,w);
                inc(st[x]);
                inc(st[y]);
                inc(ans,w);
                a[x][y]:=min(a[x][y],w);
                a[y][x]:=min(a[y][x],w);
        end;
        for k:=1 to n do
                for i:=1 to n do
                        for j:=1 to n do 
                                if a[i][j]>a[i][k]+a[k][j] then 
                                        a[i][j]:=a[i][k]+a[k][j];
        for i:=1 to n do if (st[i]>0)or(i=1) then 
                for j:=i+1 to n do if st[j]>0 then if a[i][j]=inf then begin
                        writeln(-1);
                        halt;
                end;
        for i:=0 to 1 shl n do d[i]:=inf;
        msk:=0;
        for i:=1 to n do if st[i] mod 2=0 then msk:=msk or (1 shl (i-1));
        d[msk]:=0;
        for i:=0 to 1 shl n-1 do if d[i]<>inf then
                for j:=1 to n do if (i shr (j-1))and 1=0 then if st[j] mod 2=1 then
                        for k:=j+1 to n do if (i shr (k-1))and 1=0 then if st[k] mod 2=1 then begin
                                d[i or (1 shl (j-1))or (1 shl (k-1))]:=min(d[i or (1 shl (j-1))or (1 shl (k-1))],d[i]+a[j][k]);
                        end;
        if d[1 shl n-1]=inf then begin
                writeln(-1);
                halt;
        end;
        writeln(ans+d[1 shl n-1]);
end.