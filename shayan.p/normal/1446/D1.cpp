#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 4e5 + 10, inf = 1e8;

int a[maxn], cnt[maxn];
int n;
vector<int> va[maxn];
int bef[maxn], aft[maxn], sm[maxn];

struct Solver{
    bool inside[maxn];
    int arr[maxn], C, Ls[maxn], Rs[maxn];

    Solver(){
	fill(Ls, Ls + maxn, inf);
	fill(Rs, Rs + maxn, -inf);
	C = 0;
	memset(inside, 0, sizeof inside);
    }
    void add(int pos, int x){
	x+= n;
	if(inside[x] == 0)
	    arr[C++] = x, inside[x] = 1;
	Ls[x] = min(Ls[x], pos);
	Rs[x] = max(Rs[x], pos);
    }
    int calc(){
	int ans = 0;
	for(int i = 0; i < C; i++)
	    ans = max(ans, Rs[arr[i]] - Ls[arr[i]]);
	return ans;
    }
    void rest(){
	for(int i = 0; i < C; i++){
	    int x = arr[i];
	    inside[x] = 0;
	    Ls[x] = inf;
	    Rs[x] = -inf;
	}
	C = 0;
    }
};
Solver slv;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	--a[i];
	cnt[a[i]]++;
	va[a[i]].PB(i);
    }
    vector<pii> vec;
    for(int i = 0; i < n; i++){
	if(cnt[i] != 0)
	    vec.PB({cnt[i], i});
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    if(sz(vec) == 1)
	return cout << 0 << endl, 0;
    if(vec[0].F == vec[1].F)
	return cout << n << endl, 0;
    int big = vec[0].S;

    int pt = 0;
    for(int i = 0; i <= n; i++){
	bef[i] = (pt == 0 ? -1 : va[big][pt-1]);
	if(pt < sz(va[big]) && i == va[big][pt])
	    pt++;
    }
    pt = sz(va[big])-1;
    for(int i = n; i >= 0; i--){
	aft[i] = (pt == sz(va[big])-1 ? n : va[big][pt+1]);
	if(pt >= 0 && i == va[big][pt])
	    pt--;
    }
    
    for(int i = 0; i < n; i++){ // 1 base!!!
	sm[i+1] = sm[i] + (a[i] == big);
    }
    auto solve_small = [&](int c){
			   slv.rest();
			   for(int pos : va[c]){
			       int tmp = pos;
			       int pt = sz(va[c]);
			       for(int w = 0; w < sz(va[c]) + 2 && tmp >= 0; w++){
				   tmp = bef[tmp];
				   while(pt > 0 && va[c][pt-1] >= tmp+1)
				       pt--;
				   slv.add(tmp, -sm[tmp + 1] + pt);
			       }
			   }
			   for(int pos : va[c]){
			       int tmp = pos;
			       int pt = 0;
			       for(int w = 0; w < sz(va[c]) + 2 && tmp < n; w++){
				   tmp = aft[tmp];
				   while(pt < sz(va[c]) && va[c][pt] < tmp)
				       pt++;
				   slv.add(tmp - 1, -sm[tmp] + pt);
			       }
			   }

			   return slv.calc();
		       };
    auto solve_big = [&](int c){
			 slv.rest();
			 int SM = 0;
			 slv.add(0, 0);
			 for(int i = 0; i < n; i++){
			     if(a[i] == big)
				 SM--;
			     if(a[i] == c)
				 SM++;
			     slv.add(i + 1, SM);
			 }
			 return slv.calc();
	     };
    int ans = solve_big(n + 10);
    int SQ = sqrt(n);
    for(int c = 0; c < n; c++){
	if(c != big && !va[c].empty()){
	    if(cnt[c] > SQ)
		ans = max(ans, solve_big(c));
	    else
		ans = max(ans, solve_small(c));
	}
    }
    return cout << ans << endl, 0;
}