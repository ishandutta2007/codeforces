#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2000 + 13;

vector<int> A = {2, 1, 7, 5, 6};

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(n % 2 == 1 && k % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;

    vector<int> c(n, 1);
    for(int i = n, cur = 0; ; i += 2, cur = (cur + 1) % n) {
        if(i % k == 0) {
            bool res = true;
            int cnt = i / k;
//            cout << i << ' ' << cnt << endl;
            {
//                vector<int> c1 = c;
//                for(int iter = 0; iter < cnt; iter++) {
//                    set<pii> st;
//                    for(int j = 0; j < n; j++) {
//                        st.insert({-c[j], j});
//                    }
//
//                    int j = 0;
//                    for(auto it = st.begin(); j < k; it++, j++) {
//                        c[it->s]--;
//                        if(c[it->s] < 0) {
//                            res = false;
//                            break;
//                        }
//                    }
//                }
//                c = c1;
            }


            int sum = 0;
            for(int j = 0; j < k - 1; j++) {
                sum += c[j];
                if(sum * (k - j - 1) > (i - sum) * (j + 1))
                    res = false;
            }

            if(res){
                for(int iter = 0; iter < cnt; iter++) {
                    set<pii> st;
                    for(int j = 0; j < n; j++) {
                        st.insert({-c[j], j});
                    }

                    cout << "? ";
                    int j = 0;
                    int y = 0;
                    for(auto it = st.begin(); j < k; it++, j++) {
                        cout << it->s + 1 << ' ';
    //                    y ^= A[it->s];
                        c[it->s]--;
                        if(c[it->s] < 0) {
                            res = false;
                            break;
                        }
                    }
                    cout << endl;


                    cin >> y;
                    ans ^= y;
                }
                break;

            }
        }
        c[cur] += 2;
    }


    cout << "! " << ans << endl;

}