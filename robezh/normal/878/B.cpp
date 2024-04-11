#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

deque<P> dque;

int main() {
    int n,k,m;
    int tmp;
    scanf("%d%d%d", &n, &k, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if(dque.empty() || dque.back().first != tmp) {
            dque.push_back(P(tmp, 1));
        } else {
            if(dque.back().second + 1 == k) dque.pop_back();
            else dque.back().second ++;
        }
    }
//	while(dque.size()){
//		printf("%d %d\n", dque.front().first, dque.front().second);
//		dque.pop_front();
//	}
    ll ans = 0;
    while(dque.size() > 1) {
        if(dque.front().first != dque.back().first) break;
        int x = dque.front().second, y = dque.back().second;
        int num = dque.front().first;
        if(x + y >= k) {
            dque.pop_back();
            dque.pop_front();
            ans += k;
            if(x + y > k) {
                dque.push_back(P(num, x + y - k));
                break;
            }
        } else break;
    }
    if(dque.size() == 0) {
    	//printf("size == 0\n");
        cout << ans;
    }
    else if(dque.size() == 1) {
    	//printf("size == 1\n");
    	ll remain = (ll)m * dque.front().second % k;
    	if(remain == 0) cout << "0";
    	else cout << (ll)remain + ans;
    }
    else{
    	//printf("size > 1\n");
    	while(dque.size()){
    		ans += (ll)dque.front().second * m;
    		dque.pop_front();
		}
		cout<<ans;
	}


}