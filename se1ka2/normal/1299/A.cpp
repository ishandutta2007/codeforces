#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int a[100002];
    int c[31];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j <= 30; j++){
            if((a[i] >> j) & 1) c[j]++;
        }
    }
    bool used[100002]{0};
    for(int j = 30; j >= 0; j--) if(c[j] == 1){
        for(int i = 0; i < n; i++){
            if(((a[i] >> j) & 1) && !used[i]){
                cout << a[i] << " ";
                used[i] = true;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) if(!used[i]) cout << a[i] << " ";
    cout << endl;
}