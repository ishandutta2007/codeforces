#include<bits/stdc++.h>
#define int long long
using namespace std;

int get()
{
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int gcd(int a, int b)
{
	if(a % b == 0) return b;
	else return gcd(b, a % b);
}

int block_in, block_out;
int cut_line;

int ask_in(int pos)
{
	return (pos - 1) / block_in + 1;
}

int ask_out(int pos)
{
	return (pos - 1) / block_out + 1;
}

signed main()
{
	int n = get(), m = get(), q = get();
	cut_line = gcd(n, m);
	block_in = n / cut_line;
	block_out = m / cut_line;
	for(int i = 1; i <= q; i++) {
		int opt1 = get(), pos1 = get(), opt2 = get(), pos2 = get();
		int col_1, col_2;
		if(opt1 == 1) col_1 = ask_in(pos1);
		else col_1 = ask_out(pos1);
		if(opt2 == 1) col_2 = ask_in(pos2);
		else col_2 = ask_out(pos2);
		//printf("%lld %lld\n", col_1, col_2);
		if(col_1 == col_2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}