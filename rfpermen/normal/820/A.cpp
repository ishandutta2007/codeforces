#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define piii pair<ll,pair<int,int> >
using namespace std;
ll a,c,v0,v1,l,day,read;
int main() {
    cin>>c>>v0>>v1>>a>>l;
    day=1;
    read=v0;
    while(read<c){
    	read-=l;
    	if(v0<v1)v0+=a;
    	if(v0>v1)v0=v1;
    	read+=v0;
    	day++;
	}
	cout<<day<<endl;
    return 0;
}