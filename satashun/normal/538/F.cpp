#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()

int n, sz;
int a[200010];
vector<int> seg[1 << 19];

void init(int k, int l, int r){
    if(r - l == 1){ if(l < n) seg[k].push_back(a[l]); }
    else{
	int chl = k * 2 + 1, chr = k * 2 + 2;
	init(chl, l, (l + r) / 2);
	init(chr, (l + r) / 2, r);
	seg[k].resize(seg[chl].size() + seg[chr].size());
	merge(seg[chl].begin(), seg[chl].end(), seg[chr].begin(), seg[chr].end(), seg[k].begin());
    }
}

int ask(int a, int b, int x, int k = 0, int l = 0, int r = sz){
    if(r <= a || b <= l) return 0;
    else if(l >= a && r <= b) return lower_bound(seg[k].begin(), seg[k].end(), x) - seg[k].begin();
    return ask(a, b, x, k * 2 + 1, l, (l + r) / 2) + ask(a, b, x, k * 2 + 2, (l + r) / 2, r);
}

int main(){
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);
    for(sz = 1; sz < n; sz *= 2);
    init(0, 0, sz);

    int ret = 0; // k=1
    rep(i, n - 1) ret += (a[i] > a[i+1]);
    printf("%d", ret);

    for(int k = 2; k < n; ++k){
	ret = 0;
	for(int l = 1; l < n; l += k){
	    int r = min(l + k, n);
	    ret += ask(l, r, a[(l-1)/k]);
	}
	printf(" %d", ret);
    }
    puts("");
    return 0;
}