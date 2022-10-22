#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int h[1002];
        for(int i = 0; i < n; i++) cin >> h[i];
        for(int i = 0; i < n; i++){
            if(i > 0){
                m += min(h[i - 1], h[i - 1] - (h[i] - k));
                if(m < 0){
                    printf("NO\n");
                    break;
                }
            }
        }
        if(m >= 0) printf("YES\n");
    }
}