#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int d[1005];
        int k = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a == 1) d[k++] = 1;
            else{
                while(a != d[k - 1] + 1) k--;
                d[k - 1]++;
            }
            for(int j = 0; j < k; j++){
                cout << d[j];
                if(j != k - 1) cout << '.';
            }
            cout << endl;
        }
    }
}