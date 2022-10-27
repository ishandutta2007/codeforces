#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, k, t;
int nxt[200000+10], cnt = 0;
std::vector<pii> v;
int main() {
    cin >> n >> k;
    for(int i = 2; i <= k + 1; ++ i) {
        v.push_back(make_pair(1, i));
    }
    for(int i = k + 2; i <= n; ++ i) {
        v.push_back(make_pair(i, i - k));
    } 
    
    if(n%k == 1) cnt = 2 * ((n - 1) / k);
    else if(n%k == 2 || (n%k == 0 && k == 2)) cnt = 2 * ((n-1) / k) + 1;
    else cnt = 2 * ((n - 1) / k) + 2;

    printf("%d\n", cnt);
    for(int i=0;i<v.size();i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }

}