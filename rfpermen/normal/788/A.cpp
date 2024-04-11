#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
ll N,x[600000],y[600000],best,tmp,mins,idx;
int main(){
	cin>>N;
	rep(i,N)cin>>y[i], x[i-1]=abs(y[i-1]-y[i]);
	best=0, idx=1;
	while(idx<=N-1){
		tmp=x[idx];
		best=max(best,tmp);
		mins=1;
		while(idx<=N-1){
			idx++;
			if(mins&1)tmp-=x[idx];
			else tmp+=x[idx], best=max(best,tmp);
			if(tmp<0){
				idx++;
				break;
			}
			mins++;
		}
	}idx=2;
	while(idx<=N-1){
		tmp=x[idx];
		best=max(best,tmp);
		mins=1;
		while(idx<=N-1){
			idx++;
			if(mins&1)tmp-=x[idx];
			else tmp+=x[idx], best=max(best,tmp);
			if(tmp<0){
				idx++;
				break;
			}
			mins++;
		}
	}
	cout<<best<<endl;
	return 0;
}