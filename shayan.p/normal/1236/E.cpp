// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn], f1[maxn], f2[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    if(n == 1)
	return cout << 0 << endl, 0;
    for(int i = 0; i < m; i++){
	cin >> a[i];
    }

    {
	map<int, int> st;
	for(int i = 1; i <= n; i++){
	    st[i] = 1;
	}
	int lz = 0;
	for(int i = 0; i < m; i++){
	    lz++;
	    if(st.count(n+1-lz))
		st[n-lz]+= st[n+1-lz], st.erase(n+1-lz);
	    if(st.count(a[i]-lz))
		st[a[i]-lz-1]+= st[a[i]-lz], st.erase(a[i]-lz);	    
	}
	lz++;
	if(st.count(n+1-lz))
	    st[n-lz]+= st[n+1-lz], st.erase(n+1-lz);
	int pt = 1;
	for(auto x : st){
	    pii p = x;
	    p.F+= lz;
	    while(p.S--)
		f1[pt] = p.F, pt++;
	}
    }
    {
	map<int, int> st;
	for(int i = 1; i <= n; i++){
	    st[i] =1;
	}
	int lz = 0;
	for(int i = 0; i < m; i++){
	    lz--;
	    if(st.count(-lz))
		st[-lz+1]+= st[-lz], st.erase(-lz);
	    if(st.count(a[i]-lz))
		st[a[i]-lz+1]+= st[a[i]-lz], st.erase(a[i]-lz);
	}
	lz--;
	if(st.count(-lz))
	    st[-lz+1]+= st[-lz], st.erase(-lz);
	int pt = 1;
	for(auto x : st){
	    pii p = x;
	    p.F+= lz;
	    while(p.S--)
		f2[pt] = p.F, pt++;
	}
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
	ans+= f1[i] - f2[i] +1;
    }
    return cout << ans << endl, 0;
}