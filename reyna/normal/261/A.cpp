#include <iostream>
#include <algorithm>
using namespace std;
int Min = 1000*1000*1000+7;
int q[123456];
int arr[123456];
int V[123456];
int main(){
    int m;
    cin >> m;
    for(int i = 0; i < m;i++){
        cin >> q[i];
        Min = min(q[i],Min);
    }
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    long long ans = 0;
    sort(arr,arr+n);
    for(int i = n-1;i >= 0; i -= Min+2){
        for(int j = 0; j < Min ;j++){
            if(j > i)
                break;
            ans += arr[i-j];
        }
    }
    cout << ans << endl;
    return 0;
}