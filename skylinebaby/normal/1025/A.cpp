#include<bits/stdc++.h>
using namespace std;
int a[36];
string s;
int main()
{
	int n;
	scanf("%d",&n);
	cin>>s;
	for(int i = 0;i<n;i++) {
		a[s[i]-'a']++;
	}
	if (n==1) printf("Yes\n");
	if (n==1) return 0;
	int x=0;
	int y = 0;
	for(int i = 0;i<26;i++)
	{
		if(a[i]==1) x++;
		if(a[i]>1) y++;
	}
	if(y==0) printf("No\n");
	else printf("Yes\n");
}