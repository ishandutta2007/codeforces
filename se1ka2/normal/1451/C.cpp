#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        int c[30]{0}, d[30]{0};
        for(int i = 0; i < n; i++){
            c[a[i] - 'a']++;
            d[b[i] - 'a']++;
        }
        bool f = true;
        for(int i = 0; i < 26; i++){
            while(c[i] > d[i]){
                c[i] -= k;
                c[i + 1] += k;
            }
            if(c[i] < d[i]) f = false;
        }
        if(f) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}