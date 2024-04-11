#include <cstdio>
#include <algorithm>
#define Maxn 100001

using namespace std;

int n , ans , a[Maxn];

int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d" , &a[i]);
	sort(a + 1 , a + n + 1);
	if(a[1] != 0)
		ans = 1;
	for(int i = 2 ; i <= n ; i++)
		if(a[i - 1] != a[i] && a[i] != 0)
			ans++;
	printf("%d\n" , ans);
	return 0;
}

// By Sooke.
// CF992A Nastya and an Array.