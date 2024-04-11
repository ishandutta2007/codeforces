//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
const int Maxn = 1e6 + 9;
vector<int> arr[Maxn];
int pos[Maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    For(i,0,n){
        int cur;
        cin >> cur;
        arr[cur].push_back(i);
    }
    int cur = 0;
    int ans = 0;
    while(ans != n && cur >= 0){
        if(arr[cur].size() == 0){
            cur -= 3;
            continue;
        }
        int lst = arr[cur][arr[cur].size()-1];
        arr[cur].pop_back();
        pos[ans++] = lst + 1;
        cur++;
    }
    if(ans != n){
        cout << "Impossible\n";
        return 0;
    }
    cout << "Possible\n";
    For(i,0,n){
        cout << pos[i] << ' ';
    }
    return 0;
}