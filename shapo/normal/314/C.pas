program task;

{$O+,R-,S-,Q-,I-}

const maxn = 100500;
const maxk = 131072;
const MD = 1000000007;

var a, init, sm : array[0..maxn] of longint;
	n, curk, i, cnt : longint;
	tree : array[1..2 * maxk] of longint;

procedure qsort(l, r : longint);
var i, j, x, tmp : longint;
begin
	i := l;
	j := r;
	x := sm[l + random(r - l + 1)];
	repeat
		while (sm[i] < x) do inc(i);
		while (sm[j] > x) do dec(j);
		if (i <= j) then begin	
			tmp := sm[i];
			sm[i] := sm[j];
			sm[j] := tmp;
			inc(i);
			dec(j);
		end;
	until (i > j);
	if (i < r) then qsort(i, r);
	if (j > l) then qsort(l, j);
end;

function place(x : longint) : longint;
var l, r, m : longint;
begin
	l := -1;
	r := cnt;
	while (l < r - 1) do begin
		m := (l + r) div 2;
		if (a[m] >= x) then
			r := m
		else
			l := m;
	end;
	place := r;
end;

procedure upd(x, value : longint);
var par : longint;
begin
	tree[x] := value;
	par := x div 2;
	while (par <> 0) do begin
		tree[par] := (tree[par * 2] + tree[par * 2 + 1]);
		if (tree[par] >= MD) then 
			tree[par] := tree[par] - MD;
		par := par div 2;
	end;
end;

procedure add(a : longint; var b : longint);
begin
	b := b + a;
	if (b >= MD) then
		b := b - MD;
end;

function sum(ll, rr : longint) : longint;
var res, l, r : longint;
begin
	res := 0;
	l := (ll + curk - 1);
	r := (rr + curk - 1);
	while (l < r) do begin
		if ((l and 1) = 1) then
			add(tree[l], res);
		if ((r and 1) = 0) then
			add(tree[r], res);
		l := (l + 1) shr 1;
		r := (r - 1) shr 1;
	end;
	if (l = r) then
		add(tree[l], res);
	sum := res;
end;


begin
	randseed := 173826;
	randomize;
	readln(n);
	for i := 0 to n - 1 do begin
		read(sm[i]);
		init[i] := sm[i];
	end;
	qsort(0, n - 1);
	cnt := 0;
	for i := 0 to n - 1 do
		if (i = 0) or (sm[i] <> sm[i - 1]) then begin
			inc(cnt);
			a[cnt] := sm[i];
		end;
	curk := 2;
	while (curk < cnt) do
		curk := curk shl 1;
	for i := 1 to 2 * curk - 1 do
		tree[i] := 0;
	for i := 0 to n - 1 do begin
		sm[i] := place(init[i]);
		upd(sm[i] + curk - 1, longint(int64(init[i]) * int64(sum(1, sm[i]) + 1) mod MD));
	end;
	writeln(sum(1, cnt));
end.