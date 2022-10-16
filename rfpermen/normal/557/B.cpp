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
double w,a[200005],mx,ans;
int n;
int main(){
	cout<<setprecision(7);
	cin>>n>>w;
	rep(i,1,2*n)scanf("%lf",&a[i]);
	sort(a+1,a+1+2*n);
	mx=w/3/n;
	rep(i,1,n){
		if(mx>a[i])mx=a[i];
	}
	rep(i,n+1,n*2){
		if(mx>a[i]/2)mx=a[i]/2;
	}
	cout<<mx*3*n<<endl;
}