#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 200;
int n , m , q;
vector< pair<int , int> > e[N];
pair<int , int> Q[N];
map< pair<int , int>  , int> res;
int ans[N] , f[N];

int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}

void work() {
    int i , j , x , y , z;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= m ; ++ i) {
	scanf("%d%d%d",&x,&y,&z);
	e[z].push_back(make_pair(x , y));
    }
    scanf("%d",&q);
    for (i = 1 ; i <= q ; ++ i) {
	scanf("%d%d",&x,&y);
	Q[i] = make_pair(x , y);
    }
    for (i = 1 ; i <= m ; ++ i) {
        vector<int> v;
        for (auto it : e[i]) {
            v.push_back(it.first);
            v.push_back(it.second);
	}
	sort(v.begin() , v.end());
	v.erase(unique(v.begin() , v.end()) , v.end());
        for (auto x : v)
            f[x] = x;
        for (auto it : e[i]) {
            x = it.first , y = it.second;
            f[getf(x)] = getf(y);
        }
	if (e[i].size() > M) {
            for (j = 1 ; j <= q ; ++ j) {
                x = Q[j].first , y = Q[j].second;
                if (*lower_bound(v.begin() , v.end() , x) != x)
                    continue;
                if (*lower_bound(v.begin() , v.end() , y) != y)
                    continue;               
                if (getf(x) == getf(y))
                    ++ ans[j];
            }
        } else {
            for (auto x : v)
                for (auto y : v)
                    if (x != y && getf(x) == getf(y))
                        ++ res[make_pair(x , y)];
	}
    }
    for (i = 1 ; i <= q ; ++ i) {
        x = Q[i].first , y = Q[i].second;
        printf("%d\n" , ans[i] + res[make_pair(x , y)]);
    }

}

int main() {
    //freopen("1" , "r" , stdin);
    //int _;
    //scanf("%d",&_);
    // while (_ --)
    work();

    return 0;
}