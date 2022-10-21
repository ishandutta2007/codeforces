#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

int n;
string s;
int x, y;
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
int drc[250];


bool check(int ans){
    int c_x = -x, c_y = -y;
//    int cnt[4] = {0,0,0,0};
    for(int i = 0; i < n; i++){
        int d = drc[s[i]];
        c_x += dx[d], c_y += dy[d];
    }
    for(int i = 0; i < ans; i++){
        int d =  drc[s[i]];
        c_x -= dx[d], c_y -= dy[d];
    }
    for(int i = 0; i <= n - ans; i++){
        if(abs(c_x) + abs(c_y) <= ans) return true;
        int di = drc[s[i]];
        c_x += dx[di], c_y += dy[di];
        if(i == n - ans) break;
        int dr = drc[s[i+ans]];
        c_x -= dx[dr], c_y -= dy[dr];
    }
    return false;
}

int main(){
    drc['U'] = 0, drc['D'] = 1, drc['L'] = 2, drc['R'] = 3;

    scanf("%d", &n);
    getchar();
    getline(cin, s);
    scanf("%d%d", &x, &y);

//    cout << ((x + y) % 2 + 2) % 2 << endl;

    if(((x + y) % 2 + 2) % 2 != n % 2) return !printf("-1");
    if(abs(x) + abs(y) > n) return !printf("-1");

    int l = -1, r = n, mid;
    while(l + 1 < r){
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;

}