#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,a[N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int sum=0,mv=0;
		cin>>n;
		f(i,0,n){
			cin>>a[i];
			sum+=a[i];
		}
		f(i,2,sum){
			if(sum%i==0){
				mv=1;
			}
		}
		if(mv==1){
			cout<<n<<endl;
			f(i,1,n+1) cout<<i<<" ";
			cout<<endl;
		}
		else{
			mv=0;
			cout<<n-1<<endl;
			f(i,0,n){
				if((a[i]&1) && mv==0){
					mv=1;
				}
				else cout<<i+1<<" ";
			}
			cout<<endl;
		}
	}
}