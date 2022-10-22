#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=303;

int n,m,t,mark[N];
pair<int,int> a[N*N];
int main(){
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n>>m;
		f(i,0,n*m){
			cin>>a[i].F;
			a[i].S=i;
		}
		sort(a,a+n*m);
		f(i,0,n*m){
			int j=0;
			while(1){
				j++;
				if((i+j)%m==0 || a[i+j].F!=a[i].F) break;
			}
			reverse(a+i,a+i+j);
			i=i+j-1;
		}
		f(i,0,n*m){
			f(j,i/m*m,i)
				if(a[j].S<a[i].S){
					ans++;
					//cout<<i<<" "<<j<<endl;
					//erorp(a[j]);
					//erorp(a[i]);
				}
		}
		cout<<ans<<endl;
	}
}