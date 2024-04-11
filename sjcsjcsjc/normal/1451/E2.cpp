#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int val[100010],a[100010];
vector<int> v[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	val[1]=0;v[0].push_back(1);
	for(int i=2;i<=n;i++){
		cout<<"XOR 1 "<<i<<'\n';fflush(stdout);
		cin>>val[i];v[val[i]].push_back(i);
	}
	bool flag=false;
	for(int i=0;i<n;i++) if(v[i].size()>1){
		flag=true;
		cout<<"OR "<<v[i][0]<<" "<<v[i][1]<<'\n';fflush(stdout);
		int x;cin>>x;a[1]=x^val[v[i][0]];
		break;
	}
	if(!flag){
		int pos=0;
		for(int i=1;i<=n;i++) if(val[i]==1){
			cout<<"OR 1 "<<i<<'\n';fflush(stdout);
			int x;cin>>x;a[1]=x;pos=i;
			break;
		}
		for(int i=1;i<=n;i++) if(val[i]%2==1&&val[i]>1){
			cout<<"OR "<<pos<<" "<<i<<'\n';fflush(stdout);
			int x;cin>>x;
			if(x%2==1) a[1]--;
			break;
		}
	}
	for(int i=2;i<=n;i++){
		a[i]=a[1]^val[i];
	}
	cout<<"! ";
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<'\n';fflush(stdout);
	return 0;
}