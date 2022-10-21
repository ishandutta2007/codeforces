#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 300050;

int n, m;
string s[2][N];
string res[N];
string fres[N];
int res_cnt, res_swapped = 0;

int exchange(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            s[1][j].push_back(s[0][i][j]);
        }
    }
}

char c[4] = {'A', 'C', 'T', 'G'};

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[0][i];
    exchange();
    for(int swapped = 0; swapped < 2; swapped++){
        int sn = (swapped ? m : n);
        int sm = (swapped ? n : m);
        for(int i = 0; i < sn; i++)
            res[i].resize(sm);
        for(int k1 = 0; k1 < 4; k1++){
            for(int k2 = k1 + 1; k2 < 4; k2++){
                int tot = 0;
                int k3 = 0, k4 = 6 - k1 - k2;
                while(k3 == k1 || k3 == k2) k3++, k4--;
                char cs[2][2] = {{c[k1], c[k2]}, {c[k3], c[k4]}};
                for(int i = 0; i < sn; i++){
                    int cnt[2] = {0, 0};
                    for(int j = 0; j < sm; j++){
                        cnt[0] += (s[swapped][i][j] == cs[i%2][j%2]);
                        cnt[1] += (s[swapped][i][j] == cs[i%2][(j+1)%2]);
                    }
                    int mx = cnt[0] > cnt[1] ? 0 : 1;
                    tot += cnt[mx];
                    for(int j = 0; j < sm; j++){
                        res[i][j] = cs[i%2][(j+mx)%2];
                    }
                }
                if(tot > res_cnt){
                    res_cnt = tot;
                    res_swapped = swapped;
                    for(int i = 0; i < sn; i++) fres[i] = res[i];
                }
            }
        }
    }
//    for(int i = 0; i < m; i++){
//        cout << fres[i] << endl;
//    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(res_swapped) cout << fres[j][i];
            else cout << fres[i][j];
        }
        cout << endl;
    }
}