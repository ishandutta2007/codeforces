var a, s:array[0..200000]of longint;
    i,x,n,len:longint;
begin
	readln(n);
	for i:=1 to n do begin
		read(a[i]);
	end;
	len := 0;
	for i := 1 to n do begin
		x := a[i];
		while (len > 0) and (s[len] = x) do begin
			dec(len);
			inc(x);
		end;
		inc(len);
		s[len] := x;
	end;
	writeln(len);
	for i := 1 to len do begin
		write(s[i], ' ');
	end;
end.