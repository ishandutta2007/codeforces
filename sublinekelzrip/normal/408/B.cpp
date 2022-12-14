#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int js[200],num[200];
char a[1010],b[1010];
int main()
{
	cin>>a>>b;
	int lena=strlen(a),lenb=strlen(b);
	for(int i=0;i<lena;i++)
		js[a[i]]++;
	for(int i=0;i<lenb;i++)
		num[b[i]]++;
	int ans=0;
	for(int i=90;i<=150;i++)
		if(num[i]>0&&js[i]==0)
		{
			cout<<-1;
			return 0;
		}
		else
			ans+=min(js[i],num[i]);
		cout<<ans;
}