#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

inline ll readi() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}



void search(const vector<int> &p, vector<ll> &a, int x, ll num, ll budget) {
	while(x!=-1 && budget<p[x]) x--;
	if(x==-1){
		a.push_back(num);
		return;
	}
	ll cur=1;
	while(cur<=budget){
		search(p,a,x-1,num*cur,budget/cur);
		if(budget/cur<p[x])break;
		cur*=p[x];
	}
}

int n;
vector<int> p,q;
vector<ll> a,b;
ll k;

ll get(ll budget){
	ll res=0;
	for(ll num:a){
		if(num>budget) break;
		res+=upper_bound(b.begin(),b.end(),budget/num)-b.begin();
	}
	return res;
}

int main(){
	n=readi();
	for(int i=0;i<n;i++){
		int num=readi();
		if(i&1)q.push_back(num);
		else p.push_back(num);
	}
	k=readi();
	ll mx=1e18;
	search(p,a,p.size()-1,1,mx);
	search(q,b,q.size()-1,1,mx);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll lo=1,hi=mx;
	while(lo<hi){
		ll mid=lo+hi>>1;
		if(get(mid)>=k) hi=mid;
		else lo=mid+1;
	}
	cout<<lo<<endl;
    return 0;
}