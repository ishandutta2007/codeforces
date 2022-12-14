//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
const int LOG = 23;
int ans[(1 << LOG)];
int arr[(1 << LOG)];
void dfs(int mask,int set){
    if(ans[mask])
        return;
    ans[mask] = set;
    for(int i = 0; i < LOG;i++){
        if(!((1 << i) & mask))
            dfs(mask + (1 << i),set);
    }
    return;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++)
        scanf("%d",&arr[i]),dfs(arr[i],arr[i]);
    for(int i = 0; i < n;i++){
        if(!ans[(1 << LOG)-arr[i]-1])
            cout << -1;
        else
            cout << ans[(1 << LOG)-arr[i]-1];
        cout << ' ';
    }
    cout << endl;
    return 0;
}