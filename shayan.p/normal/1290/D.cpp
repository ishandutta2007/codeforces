// So when you feel like hope is gone, Look inside you and be strong, And you'll finally see the truth, That a hero lies in you ... 
 
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

const int maxn = 2010, mod = 1e9 + 7;
const ll inf = 1e18;

template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> p){
    out << "{ " << p.F << ", " << p.S <<" }";
    return out;
}
template<typename T> ostream& operator << (ostream& out, vector<T> v){
    out << "[ ";
    for(int i = 0; i < sz(v); i++){
	out << v[i];
	if(i != sz(v)-1)
	    out << " ,";
    }
    out << " ]";
    return out;
}

int Lim = 0;
int ASKED;

bool ask(int x){
    cout << "? "<<x+1<<endl;
    char ch;
    cin >> ch;
    assert(++ASKED <= Lim);
    return ch == 'Y';
}
void reset(){
    cout<<"R"<<endl;    
}

bool is[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,k;
    cin >> n >> k;

    Lim = (3 * n * n) / (2 * k);

    if(k > 1){
	for(int i = 0; i < n; i++){
	    if(i % k == 0)
		reset();
	    if(ask(i))
		is[i] = 1;	
	}
	reset();
    }
    int N = n/k;
    for(int i = 0; i < N; i++){
	bool frs = 0;
	set<int> st;	
	for(int j = i+1; j < N; j++){
	    int cnt1 = 0, cnt2 = 0;
	    for(int w = 0; w < k; w++)
		cnt1+= !is[i*k + w];
	    for(int w = 0; w < k; w++)
		cnt2+= !is[j*k + w];
	    if(cnt1 == 0 || cnt2 == 0)
		continue;
	    if(frs == 0){
		frs = 1;
		int pt = 0, lst = -1;
		for(int w = 0; w < k; w++){
		    while(pt < k && is[i * k + pt])
			pt++;
		    if(pt == k)
			ask(lst);
		    else{
			lst = i * k + pt;
			pt++;
			ask(lst);
		    }
		}
	    }
	    int pt = 0, lst =-1;
	    for(int w = 0; w < k; w++){
		while(pt < k && is[j * k + pt])
		    pt++;
		if(pt == k)
		    ask(lst);
		else{
		    lst = j * k + pt;
		    pt++;
		    if(ask(lst))
			is[lst] = 1;
		}
	    }
	    ask(lst);

	    int X = min(cnt1, cnt2);
	    
	    pt = 0, lst =-1;
	    for(int w = 0; w < k; w++){
		while(pt < k && is[i * k + pt])
		    pt++;
		if(pt == k)
		    ask(lst);
		else{
		    lst = i * k + pt;
		    pt++;
		    if(ask(lst) && X > 1)
			st.insert(lst);
		    X--;
		}
	    }
	}
	for(int x : st)
	    is[x] = 1;
	reset();
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
	ans+= !is[i];
    }
    return cout << "! " << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")