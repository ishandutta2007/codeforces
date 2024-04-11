#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define fi first
#define se second
#define pb push_back
int x[2005],y[2005],n,k,temp,ans;
vector<int> tmp,rel;
int main(){
	cin>>k>>n;
	rep(i,1,k)cin>>x[i];
	rep(i,1,n)cin>>y[i];
	temp=y[1];
	rep(i,1,k){
		temp-=x[i];
		rel.pb(temp);
	}
	rep(j,2,n){
		temp=y[j];
		rep(i,1,k){
			temp-=x[i];
			if(rel.size()==0){
			cout<<0<<endl;
			return 0;
		}
			rep(k,0,rel.size()-1){
				if(temp==rel[k]){
					tmp.pb(temp);
					break;
				}
			}
		}
		if(tmp.size()==0){
		cout<<0<<endl;
		return 0;
		}
		rel.clear();
		rep(i,0,tmp.size()-1)rel.pb(tmp[i]);
		tmp.clear();
	}
	sort(rel.begin(),rel.end());
	if(rel.size()==0){
		cout<<0<<endl;
		return 0;
	}
	temp=rel[0];
	ans++;
	rep(i,0,rel.size()-1){
		if(temp!=rel[i])ans++, temp=rel[i];
	}
	cout<<ans<<endl;
	return 0;
}