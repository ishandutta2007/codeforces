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

int n;
int a[1000];
int main() {
	#ifdef home
    	freopen("a.in", "r", stdin);
	    freopen("a.out", "w", stdout);
	#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
    }
    sort(a, a + n);
    vector<int> ls;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < sz(ls); j++) {
    		if (ls[j] <= a[i]) {
    			ls[j]++;
    			sort(all(ls));
    			goto a;
    		}
    	}
    	ls.pb(1);
    	sort(all(ls));
    	a:;
    }
    cout<<sz(ls)<<endl;
	return 0;
}