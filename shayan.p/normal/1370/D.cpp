// Never let them see you bleed...
// Shayan.P  2020-06-30

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

int a[maxn];
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
	cin >> a[i];
    int l = 0, r = inf;
    while(r-l > 1){
	int mid = (l+r) >> 1;
	vec.clear();
	for(int i = 0; i < n; i++){
	    if(a[i] <= mid)
		vec.PB(i);
	}
	int bg = -2, ls = -2, cnt1 = 0, cnt2 = 0;
	for(int x : vec){
	    if(ls+1 != x){
		cnt1++, ls = x;
		if(bg == -2)
		    bg = x;
	    }
	}
	cnt1 = 2 * cnt1 - 1;
	cnt1+= (bg != 0) + (ls != n-1);
	ls = -2;
	if(sz(vec))
	    ls = vec[0]-1;
	for(int x : vec){
	    if(ls+1 != x){
		cnt2++, ls = x;
	    }
	}
	cnt2 = 2 * cnt2 - 1;
	if(sz(vec) > 1)
	    cnt1 = max(cnt1, cnt2 + 1 + (ls != n-1));
	if(sz(vec) == 0)
	    cnt1 = 0;		       
	if(cnt1 >= k)
	    r = mid;
	else
	    l = mid;
    }
    return cout << r << endl, 0;
}