#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define maxn 540005
#define ld long double
#define ll long long
using namespace std;
struct cpl
{
	ld r, i;
	cpl(){r = i = 0;}
	cpl(double a, double b){r = a, i = b;}
	cpl operator + (cpl a){return cpl(r + a.r, i + a.i);}
	cpl operator - (cpl a){return cpl(r - a.r, i - a.i);}
	cpl operator * (cpl a){return cpl(r * a.r - i * a.i, r * a.i + i * a.r);}
}A[maxn], B[maxn], x[maxn]; 
int l, r[maxn];
double pi = acos(-1);
void FFT(cpl *a, int tp)
{
	for(int i = 0; i < l; i++) x[r[i]] = a[i];
	for(int i = 0; i < l; i++) a[i] = x[i];
	for(int i = 1; i < l; i <<= 1)
	{
		cpl w = cpl(cos(pi / i), tp * sin(pi / i));
		for(int j = 0; j < l; j += (i << 1))
		{
			cpl wn = cpl(1, 0);
			for(int k = 0; k < i; k++)
			{
				cpl t = wn * a[i + j + k];
				a[i + j + k] = a[j + k] - t;
				a[j + k] = a[j + k] + t;
				wn = wn * w;
			}
		}
	}
}
int n;
int a[maxn];
int xs;
int main()
{
	scanf("%d%d", &n, &xs);
	l = 1;
	while(l <= n * 2) l <<= 1;
	r[0] = 0;
	for(int i = 1; i < l; i <<= 1)
		for(int j = 0; j < i; j++)
			r[i + j] = r[j] + l / i / 2;
	int ns = 0;
	A[0].r += 1, B[n].r += 1;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] < xs) ns++;
		A[ns].r += 1, B[n - ns].r += 1;
	}
	FFT(A, 1), FFT(B, 1);
	for(int i = 0; i < l; i++)
		A[i] = A[i] * B[i];
	FFT(A, -1);
	for(int i = n; i <= 2 * n; i++)
	{
		ll n1 = (A[i].r / l + 0.5);
		if(i == n) n1 = (n1 - n - 1) / 2;
		printf("%lld ", n1);
	}
	return 0;
}