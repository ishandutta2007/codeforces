//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 9;
int arr[Maxn],sr[Maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        sr[i] = arr[i];
    }
    sort(sr,sr+n);
    int x = 0;
    for(int i = 0; i < n;i++)
        if(sr[i] != arr[i])
            x++;
    if(x <= 2){
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}