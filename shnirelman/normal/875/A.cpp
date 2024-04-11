#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(int n){
    int ans = 0;
    //cout << n;
    while(n > 0){
        ans += n % 10;
        n /= 10;

    }
    //cout << ' ' << ans << endl;
    return ans;
}

int main(){
    int n;
    cin >> n;

    int k = 0;
    vector<int> a;
    for(int i = n - 1; i >= max(1, n - 80); i--)
        if(i + sum(i) == n){
            k++;
            a.push_back(i);
        }
        
    reverse(a.begin(), a.end());

    cout << k << endl;
    for(int i = 0; i < k; i++)cout << a[i] << endl;
}