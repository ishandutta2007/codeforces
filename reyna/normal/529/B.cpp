//In the name of God
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long Maxn = 1e3 + 9;
pair<int,int> arr[Maxn];
vector<int> get;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    long long ans = Maxn * Maxn * Maxn * Maxn;
    for(long long i = 1; i <= 1000;i++){
        int add = n/2;
        long long w = 0;
        get.clear();
        for(int j = 0; j < n;j++){
            if(arr[j].second > i && arr[j].first > i)
                add = -1;
            if(arr[j].second <= i){
                if(arr[j].first <= i)
                    get.push_back(arr[j].second - arr[j].first);
                w += arr[j].first;
            }else{
                add--;
                w += arr[j].second;
            }
        }
        if(add < 0)
            continue;
        sort(get.begin(),get.end());
        int j = 0;
        while(j != get.size() && add && get[j] <= 0){
            w += get[j++];
            add--;
        }
        ans = min(ans,w * i);
    }
    cout << ans << endl;
    return 0;
}