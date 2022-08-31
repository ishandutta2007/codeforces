#include <bits/stdc++.h>
#include <set>
#include <list>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
ll MOD = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a[7005],b[7005];
    forn(i,7005) a[i]=0,b[i]=0;
    forn(i,91){
    	if(i*i>7000) break;
    	if(i!=1 && i!=0) a[i*i]=1;
    }
    forn(i,7001){
    	if(a[i]==1){
    		int t=i;
    		while(t<=7000){
    			b[t]=1;
    			t+=i;
    		}
    	}
    }
    vector<int> v1;
    forn(i,7001){
    	if(i==0) continue;
    	if(!b[i]) v1.pb(i);
    }
    vector <bitset<7000> > vq1(7001);
    forn(b,7001){
    	if(b==0) continue;
    	int temp=1;
    	while(temp*temp<=b){
    		if(b%temp==0) {vq1[b].set(temp-1,1); vq1[b].set(b/temp-1,1);}
    		temp++;
    	}
    }
    vector <bitset<7000> > vq2(7001);
    forn(b,7001){
    	if(b==0) continue;
    	forn(i,v1.size()){
    		if(v1[i]*b>7000) break;
    		vq2[b].set(v1[i]*b-1);
    	}
    }
    // cout << v1[0] << " " << v1[1] << " " << 
    int n,q;
    cin >> n >> q;
    vector <bitset<7000> > v(n);
    while(q--){
    	int qu;
    	cin >> qu;
    	if(qu==1){
    		int a,b;
    		cin >> a >> b;
    		v[a-1]=vq1[b];
    	}
    	else if(qu==2){
    		int a,b,c;
    		cin >> a >> b >> c;
    		v[a-1]=v[b-1]^v[c-1];
    	}
    	else if(qu==3){
    		int a,b,c;
    		cin >> a >> b >> c;
    		v[a-1]=v[b-1]&v[c-1];
    	}
    	else if(qu==4){
    		int a,b;
    		cin >> a >> b;
    		int ans = (v[a-1]&vq2[b]).count();
    		ans%=2;
    		cout << ans;
    	}
    }
    return 0;
}