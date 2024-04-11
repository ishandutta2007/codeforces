#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
using namespace std;
int a[maxn]; 
int pls[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), pls[a[i]] = i;
	int ns = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == i) continue;
		ns++;
		int npl = pls[i];
		a[npl] = a[i], pls[a[i]] = npl;
		a[i] = i, pls[i] = i;
	}
	if((ns + 3 * n) % 2) printf("Um_nik\n");
	else printf("Petr\n");
	return 0;
}