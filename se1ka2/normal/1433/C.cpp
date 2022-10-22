#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int a[300005];
        int l = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            l = max(l, a[i]);
        }
        bool f = false;
        for(int i = 0; i < n; i++){
            if(a[i] == l && ((i > 0 && a[i] > a[i - 1]) || (i < n - 1 && a[i] > a[i + 1]))){
                cout << i + 1 << endl;
                f = true;
                break;
            }
        }
        if(!f) cout << -1 << endl;
    }
}