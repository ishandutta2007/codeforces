#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 9;
const int maxx = 2e8;
int ans = 0;
int x[maxn], y[maxn];
int d(int a, int b){
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}
void tri(int a, int b, int c){
    if(a == b || b == c || a == c) return;
    ans = max(ans, d(a,b) + d(b,c) + d(a,c));
}
main(){
    int n;
    cin >> n;
    int mnx = maxx, mny = maxx, mxx = -maxx, mxy = -maxx;
    int i1 = 1, i2 = 1, i3 = 1, i4 = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &x[i], &y[i]);
        if(x[i] < mnx) mnx = x[i], i1 = i;
        if(x[i] > mxx) mxx = x[i], i2 = i;
        if(y[i] < mny) mny = y[i], i3 = i;
        if(y[i] > mxy) mxy = y[i], i4 = i;
    }
    for(int i = 1; i <= n; i++){
        tri(i1,i3,i);
        tri(i2,i3,i);
        tri(i1,i4,i);
        tri(i2,i4,i);
    }
    cout <<ans <<" ";
    int ans4 = 2* (mxx + mxy - mnx - mny);
    for(int i = 4; i <= n; i++)
         printf("%d ", ans4);
    cout << endl;

}