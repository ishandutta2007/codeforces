    #include <bits/stdc++.h>
    using namespace std;
    typedef pair<int, int> ii;
    typedef long long ll;
     
    vector<ii> s;
    bool keep[200005];
     
    int main() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            s.push_back(ii{arr[i], i});
        }
        sort(s.begin(), s.end());
        ll sum = 0;
        for(int i = n - 1; i >= n - m*k; i--) {
            sum += s[i].first;
            keep[s[i].second] = true;
            //cout << s[i].second << " ";
        }
        cout << sum << endl;
        int run = 0;
        for(int i = 0; i < n; i++) {
            if(keep[i]) {
                if(run == m) {
                    cout << i << " ";
                    run = 0;
                }
                run++;
            }
        }
        cout << endl;
    }