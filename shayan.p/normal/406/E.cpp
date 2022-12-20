#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

pii p[maxn];
map<pii, int> mp, mp2;
int cn[2], prv[2];

map<int, ll> ans;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
	cin >> p[i].S >> p[i].F;
	cn[p[i].S]++;
	mp[p[i]]++;
    }
    sort(p, p + m);
    ll num = 0;
    for(int i = 0; i < m; i++){
	mp2[p[i]]++;
	prv[p[i].S]++;
	int X = mp[{p[i].F, 1-p[i].S}];
	int A = prv[1-p[i].S] - mp2[{p[i].F, 1-p[i].S}];
	int B = cn[1-p[i].S] - A - X;
	num+= 1ll * A * B;
	num+= 1ll * A * X;
	num+= 1ll * X * B;
	num+= 1ll * X * (X-1) / 2;
    }
    if(num != 0)
	return cout << num << endl, 0;
    int id = -1;
    for(int i = 0; i < m-1; i++){
	if(p[i].S != p[i+1].S)
	    assert(id == -1), id = i;
    }
    auto add = [](int i, int j){
		   int num = abs(p[i].F - p[j].F);
		   ll c1 = mp[p[i]], c2 = mp[p[j]];
		   ll cnt = 0;
		   for(int k = i+1; k < j; k++){
		       ll A = (p[k] == p[i] ?  (k-i) : c1);
		       ll B = (p[k] == p[j] ? (j-k) : c2);
		       cnt+= A * B;
		   }
		   if(cnt != 0)
		       ans[num]+= cnt;		       
	       };
    if(id == -1){
	add(0, m-1);
    }
    else{
	add(0, id);
	add(id+1, m-1);
	ll c1 = mp[p[id]], c2 = mp[p[id+1]], cnt = 0;
	for(int i = 0; i < id; i++)
	    cnt+= (p[id] == p[i] ? (id-i) : c1) * c2;
	for(int i = id+2; i < m; i++)
	    cnt+= (p[id+1] == p[i] ? (i-id-1) : c2) * c1;
	if(cnt != 0)
	    ans[n-(p[id+1].F - p[id].F)]+= cnt;
    }
    return cout << (ans.rbegin()->S) << endl, 0;
}