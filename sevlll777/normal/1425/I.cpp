#include<bits/stdc++.h>
//#define int unsigned short
#define p pair<int, int>
#define endl '\n'
//const int INF = 1000000001;
const long double E = 0.00000001;

using namespace std;

vector<vector<unsigned short>> d;
vector<int> tin, tout;
vector<unsigned short> height;
int time1 = 0;

void DFS(unsigned short vertex, unsigned short h){
    tin[vertex] = time1++, height[vertex] = h;
    for (unsigned short q: d[vertex]){
        DFS(q, h+1);
    }
    tout[vertex] = time1++;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unsigned short n, k;
    cin >> n >> k;
    vector<unsigned short> a(n), s(n);
    for (unsigned short q = 0; q < n; q++){
        cin >> a[q];
        s[q] = a[q];
    }
    d.assign(n, {}), tin.assign(n, -1), tout.assign(n, -1), height.assign(n, -1);
    for (unsigned short q = 0; q < n-1; q++){
        unsigned short x;
        cin >> x;
        d[x-1].push_back(q+1);
    }
    DFS(0, 0);
    for (unsigned short q = 0; q < k; q++){
        unsigned short x;
        cin >> x;
        x--;
        int sum1 = 0;
        unsigned short num = 0;
        for (unsigned short q1 = 0; q1 < n; q1++){
            if (s[q1] < a[q1]) {
                ++s[q1];
            }
            if (s[q1] >= a[q1] && tin[q1] >= tin[x] && tout[q1] <= tout[x]){
                sum1 += height[q1], ++num, s[q1] = 0;
            }
        }
        sum1 -= (int)height[x]*num;
        cout << sum1 << ' ' << num << endl;
    }
    return 0;
}