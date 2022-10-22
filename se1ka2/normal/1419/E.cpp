#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> P;

std::vector<int> enum_prime(int n){     // containing n
    std::vector<int> res;
    if (n <= 1) return res;
    std::vector<bool> p(n + 1);
    fill(p.begin() + 2, p.end(), true);
    for(int i = 2; i <= n; i++){
        if(p[i]){
            res.push_back(i);
            for(int j = i * 2; j <= n; j += i) p[j] = false;
        }
    }
    return res;
}

void enum_div(int i, int x, vector<P> &v, set<int> &st, int p[][40]){
    if(i == (int)v.size()){
        st.insert(x);
        return;
    }
    for(int j = 0; j <= v[i].second; j++){
        enum_div(i + 1, x * p[i][j], v, st, p);
    }
}

int main()
{
    int t;
    cin >> t;
    vector<int> prime = enum_prime(100000);
    while(t--){
        int n;
        cin >> n;
        int m = n;
        vector<P> v;
        for(int p : prime){
            if(m % p == 0){
                int c = 0;
                while(m % p == 0){
                    c++;
                    m /= p;
                }
                v.push_back(P(p, c));
            }
        }
        if(m > 1) v.push_back(P(m, 1));
        int k = v.size();
        int p[40][40];
        for(int i = 0; i < k; i++){
            p[i][0] = 1;
            for(int j = 1; j <= v[i].second; j++) p[i][j] = p[i][j - 1] * v[i].first;
        }
        set<int> st;
        enum_div(0, 1, v, st, p);
        vector<int> q[40];
        for(int i = 0; i < k; i++){
            auto itr = st.begin();
            while(itr != st.end()){
                auto itr2 = itr;
                itr++;
                if(*itr2 % v[i].first == 0){
                    q[i].push_back(*itr2);
                    st.erase(itr2);
                }
            }
        }
        if(k == 1){
            for(int j = 1; j <= v[0].second; j++) cout << p[0][j] << " ";
            cout << endl;
            cout << 0 << endl;
        }
        else if(k >= 3){
            for(int i = 0; i < k; i++){
                for(auto x : q[i]){
                    if(x != v[i].first * v[(i + 1) % k].first && x != v[(i + k - 1) % k].first * v[i].first){
                        cout << x << " ";
                    }
                }
                cout << v[i].first * v[(i + 1) % k].first << " ";
            }
            cout << endl;
            cout << 0 << endl;
        }
        else{
            if(v[0].second + v[1].second == 2){
                cout << v[0].first << " " << v[1].first << " " << n << " " << endl;
                cout << 1 << endl;
            }
            else{
                for(int i = 0; i < k; i++){
                    for(auto x : q[i]){
                        if(x != v[0].first * v[1].first && x != n){
                            cout << x << " ";
                        }
                    }
                    if(i == 0) cout << v[0].first * v[1].first << " ";
                    else cout << n << " ";
                }
                cout << endl;
                cout << 0 << endl;
            }
        }
    }
}