#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < m; i++)cin >> b[i];

    int i1 = 0, i2 = 0, sum1 = a[0], sum2 = b[0];
    int ans = 0;
    while(i1 < n - 1 || i2 < m - 1){
        if(sum1 == sum2){
            sum1 = 0;
            sum2 = 0;
            ans++;
        }

        if(sum1 >= sum2){
            i2++;
            sum2 += b[i2];
        }
        else{
           i1++;
           sum1 += a[i1];
        }
    }
    
    ans++;
    cout << ans;
}