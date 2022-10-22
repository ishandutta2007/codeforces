#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll t,n,s,a[100099],mx,an,sum,ans;
int main(){
	cin>>t;
	f(t1,0,t){
		cin>>n>>s;
		an=0,mx=0,sum=0,ans=0;
		f(i,1,n+1){
			cin>>a[i];
			sum+=a[i];
			if(a[i]>mx){
				mx=a[i];
				an=i;
			}
			if(sum>s && ans==0){
				ans=an;
			}
		}
		cout<<ans<<endl;
	}
}