#include<bits/stdc++.h>
using namespace std;
int n,s;
int main()
{
	scanf("%d %d",&n,&s);
	int k=n;
	if(k<s-n+1)
	{
		puts("YES");
		for(int i=1;i<n;i++)
			cout<<"1 ";
		cout<<s-n+1<<endl;
		cout<<k;
	}
	else
		puts("NO");
	return 0;
}