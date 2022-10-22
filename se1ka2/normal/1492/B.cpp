#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p[100005], q[100005];
        for(int i = 0; i < n; i++){
            cin >> p[i];
            q[p[i]] = i;
        }
        bool b[100005];
        for(int i = 1; i <= n; i++) b[i] = false;
        int right = n;
        for(int i = n; i > 0; i--){
            if(!b[i]){
                for(int j = q[i]; j < right; j++){
                    cout << p[j] << " ";
                    b[p[j]] = true;
                }
                right = q[i];
            }
        }
        cout << endl;
    }
}