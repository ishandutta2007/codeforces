#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;
const int N = 2e5 + 1;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int t, n, q, a[N], p, x;
bool canuse[N];
vector<int> gcds, tmp;
vector<long long> sum[N];
multiset<long long> st;

int main(){
	scanf("%d", &t);
    while(t--){
        memset(canuse + 1, 0, sizeof(bool) * n);
        st.clear();
        gcds.clear();
        scanf("%d%d", &n, &q);
        canuse[n] = true;
        for (int i = 1; i <= n; i++){
            sum[i].clear();
            scanf("%d", &a[i]);
            int d = gcd(i, n);
            if(!canuse[d]){
                canuse[d] = true;
                gcds.push_back(d);
            }
        }
        tmp.clear();
        for(int d : gcds){
            bool flag = true;
            for (int i = d + d; i < n; i += d)
                if(canuse[i])
                    flag = false;
            if(flag){
                tmp.push_back(d);
                sum[d].resize(d);
            }
        }
        gcds = tmp;
        for (int i = 1; i <= n; i++)
            for(auto d : gcds)
                sum[d][i % d] += a[i];
        for(int d : gcds)
            for(long long x : sum[d])
                st.insert(x * d);
        printf("%lld\n", *--st.end());
        while(q--){
            scanf("%d%d", &p, &x);
            for(int d : gcds){
                st.erase(st.find(d * sum[d][p % d]));
                sum[d][p % d] -= a[p];
                sum[d][p % d] += x;
                st.insert(d * sum[d][p % d]);
            }
            a[p] = x;
            printf("%lld\n", *--st.end());
        }
    }
	return 0;
}