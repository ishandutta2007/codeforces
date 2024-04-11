#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#define ld double
#define maxn 4000005
using namespace std;
struct cpl
{
	double r, i;
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
struct th
{
	vector<int> ns;
	void upd()
	{
		for(int i = 0; i < ns.size(); i++)
		{
			if(ns[i] >= 10)
			{
				if(i == ns.size() - 1)
					ns.push_back(0);
				ns[i + 1] += ns[i] / 10, ns[i] %= 10;
			}
		}
	}
	void mt(int a)
	{
		for(int i = 0; i < ns.size(); i++)
			ns[i] *= a;
		upd();
	}
	void otp()
	{
		for(int i = ns.size(); i >= 0; i--)
			cout<<ns[i]<<" ";
		cout<<endl;
	}
};
th mult(th n1, th n2)
{
	int n = n1.ns.size(), m = n2.ns.size();
	l = 1;
	while(l < n + m) l <<= 1;
	r[0] = 0;
	for(int i = 1; i < l; i <<= 1)
		for(int j = 0; j < i; j++)
			r[i + j] = r[j] + l / i / 2;
	for(int i = 0; i < l; i++)
		A[i] = B[i] = cpl(0, 0);
	for(int i = 0; i < n; i++)	
		A[i].r = n1.ns[i], B[i].r = n2.ns[i];
	FFT(A, 1), FFT(B, 1);
	for(int i = 0; i < l; i++)
		A[i] = A[i] * B[i];
	FFT(A, -1);
	int mxs = 0;
	for(int i = l - 1; i >= 0; i--)
		if(int(A[i].r / l + 0.001)) 
		{
			mxs = i;
			break;
		}
	th ans;
	for(int i = 0; i <= mxs; i++)
		ans.ns.push_back(int(A[i].r / l + 0.001));
	ans.upd();
	return ans;
}
th ksm(int b)
{
	if(!b)
	{
		th ans;
		ans.ns.push_back(1);
		return ans;
	}
	th ans = ksm(b >> 1);
	ans = mult(ans, ans);
	if(b & 1) ans.mt(3);
	return ans;
}
ld lg = 0.47712125471966;
char inp[maxn];
th n1, n2;
int main()
{
	scanf("%s", inp);
	if(strlen(inp) == 1)
	{
		if(inp[0] <= '4') printf("%d\n", inp[0] - '0');
		else if(inp[0] <= '6') printf("5\n");
		else printf("6\n");
		return 0;
	}	
	int nlen = strlen(inp);
	for(int i = 0; nlen - 1 - i > i; i++)
		swap(inp[i], inp[nlen - 1 - i]);
	lg = 1 / lg;
	int ns = lg * strlen(inp);
	int ll = ns - 4, rr = ns + 1;
	if(ll < 0) ll = 0;
	n1 = ksm(ll);
//	cout<<ll<<endl;
//	n1.otp();
	int ans = rr * 3 + 100;

	for(int i = ll; i <= rr; i++)
	{
		n2 = n1;
		for(int j = 0; j < 3; j++)
		{
			bool flag = 1;
			if(nlen > n2.ns.size()) flag = 0;
			else if(nlen == n2.ns.size())
				for(int k = nlen - 1; k >= 0; k--)
					if(inp[k] - '0' != n2.ns[k])
					{
						flag = (inp[k] - '0') < n2.ns[k];
						break;
					} 
			if(flag) ans = min(ans, j * 2 + i * 3);
			n2.mt(2);
		}
		n1.mt(3); 
	}
	printf("%d\n", ans);
	return 0;
}