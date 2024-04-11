#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int p[100005];
        for(int i = 0; i <= k; i++) p[i] = i;
        for(int i = k * 2 - n; i <= k; i++){
            if(i == p[i]) swap(p[i], p[k - (i - (k * 2 - n))]);
        }
        for(int i = 1; i <= k; i++) cout << p[i] << " ";
        cout << endl;
    }
}