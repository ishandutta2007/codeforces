#include <stdio.h>  
#include <vector>
#define ll long long 
using namespace std;
int main() 
{                  
	int n, k, cnt = 0;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		if (a[i] <= 0)
			break;
		if (a[i] >= a[k - 1]) ++cnt;	
	}        
	printf("%d", cnt);
}