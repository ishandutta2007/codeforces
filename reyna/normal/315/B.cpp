//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 1e5 + 1e3;
long long arr[Maxn];
long long val[Maxn];
long long cte;
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n;i++)
        cin >> arr[i];
    for(int i = 0; i < m;i++){
        int t;
        cin >> t;
        if(t == 1){
            long long v,x;
            cin >> v >> x;
            --v;
            val[v] += x - (val[v] + arr[v] + cte);
        }else if(t == 2){
            long long y;
            cin >> y;
            cte += y;
        }else{
            int q;
            cin >> q;
            cout << val[--q] + arr[q] + cte << endl;
        }
    }
    return 0;
}