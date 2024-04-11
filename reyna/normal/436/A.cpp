//In the name of God
#include <iostream>
#include <cstring>
using namespace std;
const int Maxn = 2015;
int h[Maxn],m[Maxn],t[Maxn],mark[Maxn];
int main(){
    int n,x;
    cin >> n >> x;
    int tmp = x;
    int cur = 0;
    for(int i = 0; i < n;i++)
        cin >> t[i] >> h[i] >> m[i];
    int best = 0;
    int ans = 0;
    while(best+1){
        best = -1;
        for(int i = 0; i < n;i++)
            if(!mark[i] && t[i] != cur && h[i] <= x)
                if(best == -1 || m[best] <= m[i])
                    best = i;
        if(best == -1)
            break;
        x += m[best];
        mark[best] = 1;
        ans++;
        cur = t[best];
    }
    cur = 1;
    memset(mark,0,sizeof mark);
    x = tmp;
    int out = ans;
    ans = 0;
    best = 0;
    while(best+1){
        best = -1;
        for(int i = 0; i < n;i++)
            if(!mark[i] && t[i] != cur && h[i] <= x)
                if(best == -1 || m[best] <= m[i])
                    best = i;
        if(best == -1)
            break;
        x += m[best];
        mark[best] = 1;
        ans++;
        cur = t[best];
    }
    cout << max(out,ans) << endl;
    return 0;
}