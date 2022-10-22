#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int c[10002];
    for(int i = 0; i < n * k; i++){
        cin >> c[i];
        c[i]--;
    }
    int ansl[102], ansr[102];
    for(int t = 0; t < n; t += k - 1){
        int e[102];
        int l = t, r = min(t + k - 1, n);
        bool b[102]{0};
        int i = 0;
        for(int s = 0; s < k - 1; s++){
            for(int j = l; j < r; j++) e[j] = -1;
            for(; i < n * k; i++){
                if(c[i] >= l && c[i] < r && e[c[i]] != -1 && !b[c[i]]){
                    ansl[c[i]] = e[c[i]], ansr[c[i]] = i;
                    b[c[i]] = true;
                    break;
                }
                e[c[i]] = i;
            }
            i++;
        }
    }
    for(int i = 0; i < n; i++) cout << ansl[i] + 1 << " " << ansr[i] + 1 << endl;
}