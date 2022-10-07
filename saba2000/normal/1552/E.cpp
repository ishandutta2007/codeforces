#include<bits/stdc++.h>
using namespace std;
vector<int> v[109];
int f[109];
int ans[109];
int c[100009];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n*k; i++){
        cin >> c[i];
        v[c[i]].push_back(i);
    }
    for(int l = 1; l <= n; l+=k-1){
        int r = min(n, l + k - 2);
        for(int i = 1; i < k; i++){
            int m = -1;
            for(int j = l; j <= r; j++){
                if(f[j] == 0 && (m == -1 || v[j][i] < v[m][i]))
                    m = j;
            }
            if(m == -1) break;
            f[m] = 1;
            
            ans[m] = i;

        }
    }
    for(int i = 1; i <= n; i++)
        cout<<v[i][ans[i]-1]<<" "<<v[i][ans[i]]<<endl;

}