#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#include<set>
#include<ctime>
#include<cassert>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()


int main() {
	#ifdef home
    	freopen("a.in", "r", stdin);
	    freopen("a.out", "w", stdout);
	#endif
	int n;
    scanf("%d", &n);
    int res1 = 0;
    int res2 = 0;
    vector<int> ls;
    for (int i = 0; i < n; i++) {
    	int x, y;
    	scanf("%d", &x);
    	for (int j = 0; j < x; j++) {
    		scanf("%d", &y);
    		if (x % 2 == 0) {
    			if (j < x / 2) {
    				res1 += y;
    			} else {
    				res2 += y;
    			}
    		} else {
    			if (j < x / 2) {
    				res1 += y;
    			} else 
    			if (j == x / 2) {
    				ls.pb(y);
    			} else {
    				res2 += y;
    			}
    		}
    	}
    }
    sort(all(ls));
    reverse(all(ls));
    for (int i = 0; i < sz(ls); i++) {
    	if (i % 2 == 0) {
    		res1 += ls[i];
    	} else {
    		res2 += ls[i];
    	}
    }
    cout<<res1<<" "<<res2<<endl;
	return 0;
}