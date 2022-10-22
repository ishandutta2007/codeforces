#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int q[100005];
        for(int i = 0; i < n; i++) cin >> q[i];
        bool f = true;
        int p[100005];
        int l[100005], u[100005];
        for(int i = 0; i <= n; i++) l[i] = u[i] = 0;
        int now = 0;
        for(int i = 0; i < n; i++){
            if(q[i] > now){
                p[i] = q[i];
                now = q[i];
                l[i] = 1;
                u[now] = 1;
            }
        }
        int k = 1;
        for(int i = 0; i < n; i++){
            if(l[i]) continue;
            while(u[k]) k++;
            p[i] = k;
            if(p[i] > q[i]){
                cout << -1 << endl;
                f = false;
                break;
            }
            k++;
        }
        if(!f) continue;
        for(int i = 0; i < n; i++) cout << p[i] << " ";
        cout << endl;
    }
}