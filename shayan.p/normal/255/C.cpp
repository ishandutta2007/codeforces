#include<bits/stdc++.h>
using namespace std;
int dp[4010][4010];
int num[1000010];
int hf[1000010];
set<int> st;
int main()
{
	int n,Max=0;cin>>n;int a[n+10];for(int i=0;i<n;i++) {cin>>a[i];st.insert(a[i]);Max=max(Max,++num[a[i]]);}
	Max--;
	int h=0;
	for(set<int>::iterator it=st.begin();it!=st.end();it++) {hf[*it]=h++;} 
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
		{
		int h1=hf[a[i]],h2=hf[a[j]];
		if(h1==h2) continue;
		dp[h2][h1]=max(dp[h2][h1],dp[h1][h2]+1);
		Max=max(dp[h2][h1],Max);
		}
		cout<<Max+1;
}