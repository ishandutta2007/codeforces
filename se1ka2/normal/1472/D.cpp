#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, greater<ll>());
        ll A = 0, B = 0;
        for(int i = 0; i < n; i++){
            if(!(i % 2)){
                if(!(a[i] % 2)) A += a[i];
            }
            else{
                if(a[i] % 2) B += a[i];
            }
        }
        if(A > B) cout << "Alice" << endl;
        else if(A == B) cout << "Tie" << endl;
        else cout << "Bob" << endl;
    }
}