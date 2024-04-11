#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n;
        cin >> n;
        int p[102];
        int b[102];
        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i]--;
            b[p[i]] = i;
        }
        int last = 0;
        for(int i = 0; i < n; i++){
            int now = b[i];
            int l = max(last, now);
            while(now > last){
                if(p[now - 1] < p[now]) break;
                swap(p[now], p[now - 1]);
                now--;
            }
            last = l;
        }
        for(int i = 0; i < n; i++) cout << p[i] + 1 << " ";
        cout << endl;
    }
}