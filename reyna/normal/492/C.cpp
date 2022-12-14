// In the name of God
#include <iostream>
#include <algorithm>
using namespace std;
pair<long long,long long> arr[100000+20];
int main(){
    long long n,r,avg;
    cin >> n >> r >> avg;
    long long ans = 0;
    long long grade = 0;
    long long get = avg*n;
    for(int i = 0; i < n;i++){
        cin >> arr[i].second >> arr[i].first;
        grade += arr[i].second;
    }
    sort(arr,arr+n);
    int ptr = 0;
    if(grade >= get){
        cout << 0 << endl;
        return 0;
    }
    while(grade != get){
        ans += min(r-arr[ptr].second,get-grade)*arr[ptr].first;
        grade+=min(r-arr[ptr].second,get-grade);
        ptr++;
    }
    cout << ans << endl;
    return 0;
}