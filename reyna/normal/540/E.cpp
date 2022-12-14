//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 9;
int fen[Maxn],arr[Maxn];
pair<int,int> sr[Maxn];
map<int,int> place_to_num;
void update(int v){
    v++;
    for(;v < Maxn;v+=v & -v)
        fen[v]++;
}
int query(int v){
    int ret = 0;
    v++;
    for(v;v;v -= v &-v)
        ret += fen[v];
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    int ed = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        int x,y;
        cin >> x >> y;
        if(!place_to_num[x])
            place_to_num[x] = x;
        if(!place_to_num[y])
            place_to_num[y] = y;
        swap(place_to_num[x],place_to_num[y]);
        arr[ed++] = x;
        arr[ed++] = y;
    }
    sort(arr,arr+ed);
    int m = unique(arr,arr+ed) - arr;
    sort(arr,arr+m);
    for(int i = 0; i < m;i++){
        int pos = arr[i];
        int x = place_to_num[pos];
        sr[i] = make_pair(x,i);
    }
    sort(sr,sr+m);
    reverse(sr,sr+m);
    long long ans = 0;
    for(int i = 0; i < m;i++){
        int x = sr[i].first,pos = sr[i].second;
        ans += query(pos);
        update(pos);
    }
    for(int i = 0; i < m;i++){
        int pos = arr[i];
        int x = place_to_num[pos];
        if(x == pos) continue;
        int pl = 0;
        if(x < pos) pl = lower_bound(arr,arr+m,x) - arr,ans += (pos - x) - abs(pl - i);
        if(x > pos) pl = upper_bound(arr,arr+m,x) - arr,ans += (x - pos) - abs(pl - i) + 1;
    }
    cout << ans << endl;
    return 0;
}