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
double n,v,mn,total,op,cur;
int main() {
	mn=180;
    cin>>n>>v;
    total=(n-2)*180/n;
    //cout<<total<<endl;
    rep(i,1,n-2){
    	cur=total*i/(n-2);
    	if(mn>abs(v-cur))mn=abs(v-cur), op=i+2;
    	//cout<<cur<<endl;
	}
	cout<<2<<" "<<1<<" "<<op<<endl;
    return 0;
}