#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[300009];
int lg[300009];
int mx[300009][21];
int mn[300009][21];
int Mx(int l, int r){
    int w = lg[r - l + 1];
    int i = mx[l][w], j= mx[r - (1<<w)+1][w];
    if(a[i] > a[j]) return i;
    else return j;
}
int Mn(int l, int r){
    int w = lg[r - l + 1];
    int i = mn[l][w], j= mn[r - (1<<w)+1][w];
    if(a[i] < a[j]) return i;
    else return j;
}
int cnt(int l, int r){
    if(l == r) return 0;
    int a = Mx(l, r), b = Mn(l, r);
    if(a > b) swap(a, b);
    return cnt(l, a) + 1 + cnt(b, r);

}
void solve(){

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        lg[i] = lg[i-1];
        if((1<<(lg[i]+1)) <= i) lg[i]++;
        mx[i][0] = i;
        mn[i][0] = i;
    }
    for(int i = 1; i < 20; i++){
        for(int j = 1; j + (1<<i) - 1 <= n; j++){
            mx[j][i] = (a[mx[j][i-1]] > a[mx[j + (1<<(i-1))][i-1]] ?
                        mx[j][i-1] : mx[j + (1<<(i-1))][i-1]);
            mn[j][i] = (a[mn[j][i-1]] < a[mn[j + (1<<(i-1))][i-1]] ?
                        mn[j][i-1] : mn[j + (1<<(i-1))][i-1]);
        }
    }
    cout << cnt(1, n)<<endl;

}
main(){
    int t; // = 1;
    cin >> t;
    while(t--){
        solve();
    }

}