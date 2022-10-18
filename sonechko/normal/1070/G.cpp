#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;

int n, m, a[N], b[N];

vector <pair<int, int> >vec;

bool dist(int guyPos, int health, int pos){
    if (guyPos < pos){
        int cur = health;
        for (int i = guyPos; i <= pos; i++){
            cur += a[i];
            if (cur < 0)
                return 0;
        }
        return 1;
    } else {
        int cur = health;
        for (int i = guyPos; i >= pos; i--){
            cur += a[i];
            if (cur < 0)
                return 0;
        }
        return 1;
    }
}

bool used[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int s, h;
        cin >> s >> h;
        vec.push_back({s, h});
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    for (int i = 1; i <= n; i++){
        queue <pair<int, int> > q;
        for (int j = 1; j <= n; j++)
            a[j] = b[j];
        vector <int> posit;
        for (int j = 0; j < vec.size(); j++){
            used[j] = 0;
            if (dist(vec[j].first, vec[j].second, i)){
                q.push({vec[j].first, j+1});
                used[j] = 1;
            }
        }
        while(!q.empty()){
            int pos = q.front().first, id = q.front().second;
            q.pop();
            posit.push_back(id);
            for (int j = min(i, pos); j <= max(i, pos); j++)
                a[j] = 0;
            for (int j = 0; j < vec.size(); j++){
                if (used[j])
                    continue;
                if (dist(vec[j].first, vec[j].second, i)){
                    q.push({vec[j].first, j+1});
                    used[j] = 1;
                }
            }
        }

        if (posit.size() == m){
            cout << i << endl;
            for (int j = 1; j <= m; j++)
                cout << posit[j-1] << ' ';
            cout << endl;
            return 0;
        }
    }
    cout << -1;


}