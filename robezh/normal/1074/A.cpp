#include <bits/stdc++.h>
using namespace std;

const int N = 100050;

int n,m;
vector<int> num, pt;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        num.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a == 1) pt.push_back(b);
    }
    m = pt.size();
    sort(num.begin(), num.end());
    sort(pt.begin(), pt.end());
    num.push_back((int)1e9);

//    if(num.size() == 0){
//        int cnt = 0;
//        for(int x : pt){
//            if(x == (int)1e9) cnt++;
//        }
//        return !printf("%d", cnt);
//    }
    int res = (int)1e9;
    int cur = 0;
    while(cur < m && pt[cur] < num[0]) cur++;
//    cout << cur << endl;
    for(int i = 0; i <= n; i++){
        res = min(res, i + m - cur);
        if(i == n) break;
        while(cur < m && pt[cur] < num[i+1]) cur++;
    }
    cout << res << endl;
}