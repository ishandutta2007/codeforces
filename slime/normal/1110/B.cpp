#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
#define mod 998244353
using namespace std;
int b[maxn], c[maxn];
int n, m, k;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		if(i) c[i] = b[i] - b[i - 1] - 1;
	}
	if(n) sort(c + 1, c + n);
	int ns = b[n - 1] - b[0] + 1;
	for(int i = n - 1; i >= n - 1 - (k - 1) + 1; i--)
		ns -= c[i];//, cout<<i<<" "<<c[i]<<endl;
	printf("%d\n", ns); 
	return 0;
}