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

const int N=1e6+99;

int n,t,a[N],mark[N];

int main(){
	cin>>t;
	while(t--){
		int ans=0,g;
		string s,t;
		cin>>n>>s>>t;
		f(i,0,n){
			if(s[i]!=t[i]) ans+=2;
			else{
				if(s[i]=='0') ans++;
				else{
					if(i && s[i-1]==t[i-1] && s[i-1]=='0' && !mark[i-1])
						mark[i-1]=1,ans++;
					else if(i<n-1 && s[i+1]==t[i+1] && s[i+1]=='0')
						mark[i+1]=1,ans++;
				}
			}
		}
		fill(mark,mark+n,0);
		cout<<ans<<endl;
	}
}