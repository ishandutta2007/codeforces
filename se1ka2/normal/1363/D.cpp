#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v[1024];
        int b[1002]{0};
        for(int i = 0; i < k; i++){
            int c;
            cin >> c;
            for(int j = 0; j < c; j++){
                int x;
                cin >> x;
                x--;
                b[x] = true;
                v[i].push_back(x);
            }
        }
        for(int i = 0; i < n; i++){
            if(!b[i]) v[k].push_back(i);
        }
        cout << "? " << n << " ";
        for(int i = 0; i < n; i++) cout << i + 1 << " ";
        cout << endl;
        cout.flush();
        int m;
        cin >> m;
        int left = 0, right = 1024;
        while(right - left > 1){
            int mid = (left + right) / 2;
            int c = 0;
            for(int i = left; i < mid; i++) c += v[i].size();
            cout << "? " << c << " ";
            for(int i = left; i < mid; i++){
                for(int x : v[i]) cout << x + 1 << " ";
            }
            cout << endl;
            cout.flush();
            int w;
            cin >> w;
            if(w < m) left = mid;
            else right = mid;
        }
        int c = n - (int)v[left].size();
        bool f[1002]{0};
        for(int x : v[left]) f[x] = true;
        cout << "? " << c << " ";
        for(int i = 0; i < n; i++){
            if(!f[i]) cout << i + 1 << " ";
        }
        cout << endl;
        cout.flush();
        int r;
        cin >> r;
        cout << "! ";
        for(int i = 0; i < k; i++){
            if(i != left) cout << m << " ";
            else cout << r << " ";
        }
        cout << endl;
        cout.flush();
        string s;
        cin >> s;
    }
}