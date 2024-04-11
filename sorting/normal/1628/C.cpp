#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int n;

void set_true(vector<vector<int>> &a, int i, int j){
    a[i][j] ^= true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        cin >> n;

        vector<vector<int>> x(n + 2, vector<int>(n + 2));
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j){
                //x[i][j] = 1;
                cin >> x[i][j];
            }

        int sum = 0;
        vector<vector<int>> a(n + 2, vector<int>(n + 2, 0));
        for(int i = 0; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(!a[i][j] && (i != 0 || (j % 4 == 1))){
                   //cout << a[i][j + 1] << " a" << endl;
                    //cout << i << " " << j << endl;
                    if(j == n || a[i][j + 1]){
                       //cout << "vertical" << endl;
                        sum ^= x[i + 1][j];
                        sum ^= x[i + 2][j];
                        set_true(a, i + 1, j);
                        set_true(a, i + 2, j);
                        set_true(a, i + 3, j);
                        set_true(a, i, j);
                        set_true(a, i + 1, j - 1);
                        set_true(a, i + 1, j + 1);
                        set_true(a, i + 2, j - 1);
                        set_true(a, i + 2, j + 1);
                    }
                    else{
                        sum ^= x[i + 1][j];
                        sum ^= x[i + 1][j + 1];

                        set_true(a, i + 1, j);
                        set_true(a, i + 1, j + 1);
                        set_true(a, i, j);
                        set_true(a, i, j + 1);
                        set_true(a, i + 2, j);
                        set_true(a, i + 2, j + 1);
                        set_true(a, i + 1, j - 1);
                        set_true(a, i + 1, j + 2);
                    }
                }
            }
        }

        /*for(int i = 1; i <= n; ++i){    
            for(int j = 1; j <= n; ++j){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }*/

        cout << sum << "\n";
    }
}