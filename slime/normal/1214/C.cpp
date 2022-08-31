#include <bits/stdc++.h>
#define maxn 500005
#define ll long long
using namespace std;
int n;
char inp[maxn]; 
int main()
{
	cin>>n;
	scanf("%s", inp);
	int fl = 0, s = 0;
	for (int i = 0; i < n; i++) {
		if (inp[i] == '(') s++;
		else s--;
		if (s <= -2) {
			printf("No\n");
			return 0;
		}
	}
	if (s) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}