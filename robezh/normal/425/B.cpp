#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int num[105][105];
int x[15], y[105];

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> num[i][j];
        }
    }
    if(n <= k){
        int fres = 100;
        for(int i = 0; i < (1 << n); i++){
            int now = i;
            for(int j = 0; j < n; j++) x[j] = now%2, now /= 2;
            int tcnt = 0;
            for(int j = 0; j < m; j++){
                int cnt = 0;
                for(int t = 0; t < n; t++){
                    cnt += (x[t] == num[t][j]);
                }
                tcnt += min(cnt, n-cnt);
            }
            fres = min(fres, tcnt);
        }
        cout << (fres > k ? -1 : fres) << endl;
    }
    else{
        int fres = 100;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                y[j] = num[i][j];
            }
            int tcnt = 0;
            for(int t = 0; t < n; t++){
                int cnt = 0;
                for(int j = 0; j < m; j++){
                    cnt += (y[j] == num[t][j]);
                }
                tcnt += min(cnt, m-cnt);
            }
            fres = min(fres, tcnt);
        }
        cout << (fres > k ? -1 : fres) << endl;
    }
}