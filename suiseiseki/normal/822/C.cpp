
 #include<bits/stdc++.h>
#define N 200010
#define mp make_pair
#define F first
#define S second
using namespace std;
int n,x,l,r,c,ans,f[N];
vector<pair<int,int> >L[N],R[N];
int main(){
    cin>>n>>x;
	for(int i=1;i<=n;i++){
	    cin>>l>>r>>c;
	    L[l].push_back(mp(r-l+1,c));
	    R[r].push_back(mp(r-l+1,c));
	}
	memset(f,0x7f,sizeof(f));
	ans=f[0];
	for(int i=1;i<N;i++){
	    for(auto j:L[i])if(j.F<x)if(f[x-j.F]<f[0])ans=min(ans,j.S+f[x-j.F]);
	    for(auto j:R[i])f[j.F]=min(f[j.F],j.S);
	}
	cout<<(ans<f[0]?ans:-1)<<endl;
	return 0;
}