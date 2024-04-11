program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

type
  tq = record
    a, b : integer;
  end;
  tp = record
    l, r : integer;
  end;

var
  l, b, f, n, k, nk, i, j : integer;
  fl : boolean;
  q : array[0..201] of tq;
  p, np : array[0..201] of tp;
  x : array[0..201] of integer;

function less(var a, b : tp) : boolean;
begin
  result := a.l < b.l;
end;

procedure sort(l, r : integer);
var ep, t : tp;
i, j : integer;
begin
  if l >= r then
    exit;
  ep := p[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while less(p[i], ep) do
      inc(i);
    while less(ep, p[j]) do
      dec(j);
    if i <= j then begin
      t := p[i];
      p[i] := p[j];
      p[j] := t;
      inc(i);
      dec(j);
    end; 
  end;
  sort(i, r);
  sort(l, j);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(l, b, f, n);
  for i := 1 to n do
    read(q[i].a, q[i].b);
  k := 0;
  for i := 1 to n do begin
    if q[i].a = 1 then begin
      x[i] := -1;
      if k = 0 then begin
        if q[i].b <= l then begin
          inc(k);
	  p[k].l := 0;
	  p[k].r := q[i].b;
	  x[i] := 0;
	end;
      end
      else begin
        fl := false;
        if p[1].l - q[i].b >= f then begin
          inc(k);
	  p[k].l := 0;
	  p[k].r := q[i].b;
	  x[i] := p[k].l;
	  sort(1, k);
	  fl := true;
	end;
        for j := 1 to k - 1 do begin
          if fl then
	    break;
          if (p[j].r + b + q[i].b < p[j + 1].l) and (p[j + 1].l - f - q[i].b > p[j].r) and (p[j + 1].l - f - p[j].r - b >= q[i].b) then begin
            inc(k);
	    p[k].l := p[j].r + b;
	    p[k].r := p[k].l + q[i].b;
	    x[i] := p[k].l;
	    sort(1, k);
	    fl := true;
	  end;
	end;
	if (not fl) and (p[k].r + b + q[i].b <= l) then begin
          inc(k);
	  p[k].l := p[k - 1].r + b;
	  p[k].r := p[k].l + q[i].b;
	  x[i] := p[k].l;
	  sort(1, k);
	end;
      end;
      writeln(x[i]);
    end
    else begin
      nk := 0;
      for j := 1 to k do
        if p[j].l <> x[q[i].b] then begin
          inc(nk);
	  np[nk] := p[j];
	end;
      k := nk;
      p := np;
    end;
  end;
end.