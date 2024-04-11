#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int xm = 0, ym = 0;
    for(int c = 0; c < n; c++){
        char p;
        cin >> p;
        if(p == '+'){
            int x, y;
            scanf("%d %d", &x, &y);
            xm = max(xm, min(x, y));
            ym = max(ym, max(x, y));
        }
        else{
            int h, w;
            scanf("%d %d", &h, &w);
            if(w < h) swap(w, h);
            if(xm <= h && ym <= w) printf("YES\n");
            else printf("No\n");
        }
    }
}