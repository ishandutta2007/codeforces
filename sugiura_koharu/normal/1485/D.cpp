#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
int a[505][505],b[505][505],qwq[1000005];
signed main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			cin >> x;
			if(i+j&1) cout << 720720 << " ";
			else cout << 720720-x*x*x*x << " ";
		}
		puts("");
	}
	return 0;
}