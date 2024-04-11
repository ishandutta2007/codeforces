#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> v,pr;
		for(int i=1;i*i<=n;i++) if(n%i==0){
			if(i>1) v.push_back(i);
			if((n/i)!=i) v.push_back(n/i);
		}
		sort(v.begin(),v.end());
		int p=n;
		for(int i=2;i*i<=p;i++){
			if(p%i==0){
				while(p%i==0) p/=i;
				pr.push_back(i);
			}
		}
		if(p>1) pr.push_back(p);
		if(pr.size()==1){
			for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
			cout<<'\n';
			cout<<0<<'\n';
		}
		else{
			if(pr.size()==2&&n==pr[0]*pr[1]){
				cout<<pr[0]<<' '<<n<<' '<<pr[1]<<'\n';
				cout<<1<<'\n';
			}
			else{
				vector<int> v1,v2,v3,w[20];
				for(int i=0;i<v.size();i++){
					if(v[i]%(pr[0]*pr[1])==0) v1.push_back(v[i]);
					else if(v[i]%pr[0]==0) v2.push_back(v[i]);
					else if(v[i]%pr[1]==0) v3.push_back(v[i]);
				}
				for(int i=0;i<v2.size();i++) cout<<v2[i]<<' ';
				cout<<v1[0]<<' ';
				for(int i=0;i<v3.size();i++) cout<<v3[i]<<' ';
				for(int i=0;i<v.size();i++) if(v[i]%pr[0]!=0&&v[i]%pr[1]!=0){
					for(int j=pr.size()-1;j>=2;j--){
						if(v[i]%pr[j]==0){
							w[j].push_back(v[i]);break;
						}
					}
				}
				for(int i=pr.size()-1;i>=2;i--){
					for(int j=0;j<w[i].size();j++) cout<<w[i][j]<<' ';
				}
				cout<<v1[v1.size()-1]<<' ';
				for(int i=1;i<v1.size()-1;i++) cout<<v1[i]<<' ';
				cout<<'\n';
				cout<<0<<'\n';
			}
		}
	}
	return 0;
}