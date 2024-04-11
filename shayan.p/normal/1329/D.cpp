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

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int cnt[26];
queue<int> poses[2][26];
set<int> st;
vector<pii> ans;

string s;

int N;

struct fenwick{
    int fn[maxn];
    void reset(){
	fill(fn, fn+N+5, 0);
    }    
    void add(int pos){
	for(pos+=3; pos < N + 5; pos+= pos & -pos)
	    fn[pos]++;
    }
    int ask(int pos){
	int ans = 0;
	for(pos+= 3; pos > 0; pos-= pos & -pos)
	    ans+= fn[pos];
	return ans;
    }
};fenwick fn;

pii fnd(int c){
    while(sz(poses[0][c])){
	int x = poses[0][c].front();
	auto it = st.upper_bound(x);
	if(st.count(x) && it != st.end() && s[x] != s[*it])
	    return {x, *it};
	poses[0][c].pop();
    }
    while(sz(poses[1][c])){
	int x = poses[1][c].front();
	auto it = st.lower_bound(x);
	if(st.count(x) && it != st.begin() && s[x] != s[*prev(it)])
	    return {*prev(it), x};
	poses[1][c].pop();
    }
    return {-1, -1};
}
void del(int a, int b){
    auto it1 = st.find(a);
    auto it2 = st.find(b);
    if(it1 != st.begin() && next(it2) != st.end()){
	int i = *prev(it1), j = *next(it2);
	if(s[i] != s[j])
	    poses[0][s[i] - 'a'].push(i), poses[1][s[j] - 'a'].push(j);
    }
    cnt[ s[a] - 'a' ]--, cnt[ s[b] - 'a' ]--;
    ans.PB({a, b});
    st.erase(it1), st.erase(it2);
}       
void solve(){
    cin >> s;
    N = sz(s);
    fn.reset();
    vector<pair<int, char> > vec;
    for(int i = 0; i < 26; i++){
	cnt[i] = 0;
    }
    for(int i = 0; i < sz(s)-1; i++){
	if(s[i] == s[i+1])
	    vec.PB({i, s[i]}), cnt[ s[i] - 'a' ]++;
    }
    for(int i = 0; i < 26; i++){
	while(sz(poses[0][i]))
	    poses[0][i].pop();
	while(sz(poses[1][i]))
	    poses[1][i].pop();
    }
    st.clear();
    ans.clear();

    for(int i = 0; i < sz(vec); i++){
	st.insert(vec[i].F);
    }
    for(int i = 0; i < sz(vec)-1; i++){	
	if(vec[i].S != vec[i+1].S){
	    poses[0][ vec[i].S - 'a' ].push(vec[i].F);
	    poses[1][ vec[i+1].S - 'a' ].push(vec[i+1].F);
	}
    }
    while(true){
	int mx = 0;
	for(int i = 1; i < 26; i++){
	    if(cnt[i] > cnt[mx])
		mx = i;
	}
	pii p = fnd(mx);
	if(p.F == -1)
	    break;
	del(p.F, p.S);		
    }

    vector<pii> ANS;
    set<int> ST;
    for(int i = 0; i < N; i++)
	ST.insert(i);
    for(pii p : ans){
	auto L = ST.upper_bound(p.F), R = ST.upper_bound(p.S);
	ANS.PB({*L - fn.ask(*L), *prev(R) - fn.ask(*prev(R))});
	for(auto it = L; it != R; it++)
	    fn.add(*it);
	ST.erase(L, R);	
    }

    string ss;
    for(auto i : ST)
	ss+= s[i];
    int bef = 0;    
    for(int i = 1; i < sz(ss); i++){
	if(ss[i] == ss[i-1])
	    ANS.PB({0, i-1-bef}), bef = i;
    }
    ANS.PB({0, sz(ss)-1-bef});

    cout << sz(ANS) << "\n";
    for(pii p : ANS){
	cout << p.F+1 << " " << p.S+1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	solve();
    }
    return 0;
}