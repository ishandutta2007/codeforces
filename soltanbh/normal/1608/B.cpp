#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99;

int n,a,b,t;

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		if(a+b>n-2 || abs(a-b)>1){
			cout<<-1<<endl;
			continue ;
		}
		if(a==b){
			f(i,1,a+1){
				cout<<i<<" "<<n+1-i<<" ";
			}
			f(i,a+1,n-a+1){
				cout<<i<<" ";
			}
		}
		if(a+1==b){
			f(i,1,b+1){
				cout<<n+1-i<<" "<<i<<" ";
			}
			f(i,b+1,n-b+1){
				cout<<i<<" ";
			}
		}
		if(b+1==a){
			f(i,1,a+1){
				cout<<i<<" "<<n+1-i<<" ";
			}
			f_(i,n-a,a+1){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}		
}