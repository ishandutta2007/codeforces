#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    static pair<ll, int> a[200003];

    while(t--){
        ll n, w;
        cin >> n >> w;

        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i + 1;
        }

        sort(a, a + n);

        for(int i = n - 1; i >= 0; --i){
            if(a[i].first > w)
                n--;
            else break;
        }

        if(!n){
            cout << "-1\n";
            continue;
        }

        reverse(a, a + n);
        int i = 1;
        ll c = (w / 2ll) + (w % 2ll); 
        bool ok = false;
        while(true){
            ll sum = 0;
            for(int j = 0; j < min(i, (int)n); ++j)
                sum += a[j].first;
            if(sum >= c){
                ok = true;
                cout << min(i, (int)n) << "\n";
                for(int j = 0; j < min(i, (int)n); ++j)
                    cout << a[j].second << " ";
                cout << "\n";
                break;
            }
            
            if(i >= n) break;
            i *= 2;
        }

        if(!ok) cout << "-1\n";
    }
}