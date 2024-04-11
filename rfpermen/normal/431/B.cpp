#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define MAX 10005
using namespace std;
int n,ans,tmp,x[6][6],l;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	rep(i,1,5){
		rep(j,1,5)cin>>x[i][j];
	}
	rep(a,1,5){
		rep(b,1,5){
			if(b==a)continue;
			rep(c,1,5){
				if(c==a || c==b)continue;
				rep(d,1,5){
					if(d==a || d==b || d==c)continue;
					rep(e,1,5){
						if(e==a || e==b || e==c || e==d)continue;
						tmp=x[a][b]+x[b][a]+x[c][d]+x[d][c]+x[b][c]+x[c][b]+x[d][e]+x[e][d]+x[c][d]+x[d][c]+x[e][d]+x[d][e];
						if(ans<tmp)ans=tmp;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}