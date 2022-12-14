//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 1e3 + 20;
pair<long double,long double> arr[Maxn];
bool mark[Maxn];
int main(){
    long double n,x,y;
    cin >> n >> x >> y;
    for(int i = 0; i < n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    int ans = 0;
    bool f = 0;
    for(int i = 0; i < n;i++){
        if(mark[i])
            continue;
        if(x == arr[i].first && y == arr[i].second)
            continue;
        if(y == arr[i].second){
            if(!f)
                ans++,f = 1;
            continue;
        }
        ans++;
        long double k = (x - arr[i].first)/(y - arr[i].second);
        for(int j = i;j < n;j++){
            if((x - arr[j].first)/(y - arr[j].second) == k)
                mark[j] = 1;
        }
    }
    cout << max(ans,1) << endl;
    return 0;
}