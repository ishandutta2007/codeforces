// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int a[10];

void In(){
    int x;cin>>x;
    for(int i=0;i<x;i++){
	string s;cin>>s;
	for(int j=0;j<sz(s);j++)
	    a[s[j]-'0']=i;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    a[0]=-1;
    while(a[0]!=a[1]){
	cout<<"next 0 1"<<endl;
	In();
	cout<<"next 1"<<endl;
	In();
    }
    while(a[0]!=a[2]){
	cout<<"next ";
	for(int i=0;i<10;i++)
	    cout<<i<<" ";
	cout<<endl;
	In();
    }
    return cout<<"done"<<endl,0;
}